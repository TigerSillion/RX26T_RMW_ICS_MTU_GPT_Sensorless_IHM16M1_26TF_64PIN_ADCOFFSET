namespace PcDebugGui.Core.Sessions;

public sealed class SessionTemplate
{
    public string Name { get; init; } = string.Empty;
    public DateTime SavedAtUtc { get; init; } = DateTime.UtcNow;
    public List<string> ScopeChannels { get; init; } = [];
    public List<VariableGroup> VariableGroups { get; init; } = [];
    public Dictionary<string, string> FocParameterSnapshot { get; init; } = [];
}

public sealed class VariableGroup
{
    public string Name { get; init; } = string.Empty;
    public List<string> Variables { get; init; } = [];
}
