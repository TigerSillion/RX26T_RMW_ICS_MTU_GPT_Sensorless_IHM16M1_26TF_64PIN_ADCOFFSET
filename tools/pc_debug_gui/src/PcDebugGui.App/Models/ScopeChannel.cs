namespace PcDebugGui.App.Models;

public sealed class ScopeChannel
{
    public string Name { get; init; } = string.Empty;
    public bool Enabled { get; set; } = true;
    public string Color { get; set; } = "Lime";
    public string TriggerMode { get; set; } = "Auto";
    public double LastValue { get; set; }
}
