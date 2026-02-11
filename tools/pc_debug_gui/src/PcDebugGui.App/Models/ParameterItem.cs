namespace PcDebugGui.App.Models;

public sealed class ParameterItem
{
    public string Name { get; init; } = string.Empty;
    public string Category { get; init; } = string.Empty;
    public string Unit { get; init; } = string.Empty;
    public string Description { get; init; } = string.Empty;
    public string Value { get; set; } = string.Empty;
}
