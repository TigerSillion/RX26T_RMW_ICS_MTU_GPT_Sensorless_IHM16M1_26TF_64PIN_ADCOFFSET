using System.Collections.ObjectModel;
using PcDebugGui.App.Models;

namespace PcDebugGui.App.ViewModels;

public sealed class OscilloscopeViewModel : ViewModelBase
{
    public ObservableCollection<ScopeChannel> Channels { get; } =
    [
        new() { Name = "iq" },
        new() { Name = "id" },
        new() { Name = "speed_rpm" },
        new() { Name = "angle_est" },
    ];

    private string _triggerChannel = "iq";
    private string _timebase = "20ms/div";
    private string _zoomLevel = "x1";

    public string TriggerChannel
    {
        get => _triggerChannel;
        set => SetProperty(ref _triggerChannel, value);
    }

    public string Timebase
    {
        get => _timebase;
        set => SetProperty(ref _timebase, value);
    }

    public string ZoomLevel
    {
        get => _zoomLevel;
        set => SetProperty(ref _zoomLevel, value);
    }

    public List<string> ExportCsv()
    {
        return Channels.Where(item => item.Enabled).Select(item => $"{item.Name},{item.LastValue:F4}").ToList();
    }
}
