using PcDebugGui.App.Services;
using PcDebugGui.App.ViewModels;
using PcDebugGui.Core.Protocol;
using PcDebugGui.Core.Sessions;
using PcDebugGui.Core.Transport;

namespace PcDebugGui.App;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();

        var sessionFolder = Path.Combine(AppContext.BaseDirectory, "sessions");
        var transport = TransportFactory.CreateSerial(new SerialTransportOptions("COM3", 115200));
        var protocolClient = new McuDebugProtocolClient(transport);
        var sessionStore = new JsonSessionTemplateStore(sessionFolder);

        DataContext = new MainWindowViewModel(protocolClient, sessionStore, new DialogNotificationService());
    }
}
