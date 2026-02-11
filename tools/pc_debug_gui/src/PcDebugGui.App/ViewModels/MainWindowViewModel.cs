using System.Collections.ObjectModel;
using PcDebugGui.App.Services;
using PcDebugGui.Core.Protocol;
using PcDebugGui.Core.Sessions;
using PcDebugGui.Core.Transport;

namespace PcDebugGui.App.ViewModels;

public sealed class MainWindowViewModel : ViewModelBase
{
    private readonly IMcuDebugProtocolClient _protocolClient;
    private readonly ISessionTemplateStore _sessionStore;
    private readonly INotificationService _notificationService;

    public MainWindowViewModel(IMcuDebugProtocolClient protocolClient, ISessionTemplateStore sessionStore, INotificationService notificationService)
    {
        _protocolClient = protocolClient;
        _sessionStore = sessionStore;
        _notificationService = notificationService;

        ConnectCommand = new RelayCommand(() => ConnectAsync().GetAwaiter().GetResult());
        DisconnectCommand = new RelayCommand(() => DisconnectAsync().GetAwaiter().GetResult());
        SaveSessionCommand = new RelayCommand(() => SaveSessionAsync().GetAwaiter().GetResult());
        RestoreLatestSessionCommand = new RelayCommand(() => RestoreLatestSessionAsync().GetAwaiter().GetResult());
    }

    public ObservableCollection<TransportKind> TransportKinds { get; } = [TransportKind.Serial, TransportKind.Can, TransportKind.Ethernet];

    private TransportKind _selectedTransport = TransportKind.Serial;
    public TransportKind SelectedTransport
    {
        get => _selectedTransport;
        set => SetProperty(ref _selectedTransport, value);
    }

    private string _portName = "COM3";
    public string PortName
    {
        get => _portName;
        set => SetProperty(ref _portName, value);
    }

    private int _baudRate = 115200;
    public int BaudRate
    {
        get => _baudRate;
        set => SetProperty(ref _baudRate, value);
    }

    public FocTuningViewModel FocTuning { get; } = new();
    public OscilloscopeViewModel Oscilloscope { get; } = new();
    public RegisterBrowserViewModel RegisterBrowser { get; } = new();

    public RelayCommand ConnectCommand { get; }
    public RelayCommand DisconnectCommand { get; }
    public RelayCommand SaveSessionCommand { get; }
    public RelayCommand RestoreLatestSessionCommand { get; }

    private async Task ConnectAsync()
    {
        await _protocolClient.ConnectAsync();
        _notificationService.Info($"Connected via {SelectedTransport}.");
    }

    private async Task DisconnectAsync()
    {
        await _protocolClient.DisconnectAsync();
        _notificationService.Info("Disconnected.");
    }

    private async Task SaveSessionAsync()
    {
        var template = new SessionTemplate
        {
            Name = "default",
            SavedAtUtc = DateTime.UtcNow,
            ScopeChannels = Oscilloscope.Channels.Where(item => item.Enabled).Select(item => item.Name).ToList(),
            VariableGroups =
            [
                new VariableGroup
                {
                    Name = "Favorites",
                    Variables = RegisterBrowser.SnapshotFavoriteVariables().ToList(),
                },
            ],
            FocParameterSnapshot = FocTuning.Snapshot(),
        };

        await _sessionStore.SaveAsync(template);
        _notificationService.Info("Session template saved.");
    }

    private async Task RestoreLatestSessionAsync()
    {
        var templates = await _sessionStore.LoadAllAsync();
        var latest = templates.FirstOrDefault();

        if (latest is null)
        {
            _notificationService.Error("No session templates found.");
            return;
        }

        FocTuning.Restore(latest.FocParameterSnapshot);
        RegisterBrowser.RestoreFavorites(latest.VariableGroups.SelectMany(group => group.Variables));

        foreach (var channel in Oscilloscope.Channels)
        {
            channel.Enabled = latest.ScopeChannels.Contains(channel.Name, StringComparer.OrdinalIgnoreCase);
        }

        _notificationService.Info($"Session restored: {latest.Name}");
    }
}
