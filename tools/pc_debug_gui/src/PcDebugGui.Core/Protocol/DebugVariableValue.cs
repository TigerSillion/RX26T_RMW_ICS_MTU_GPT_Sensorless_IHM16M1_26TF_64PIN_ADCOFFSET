namespace PcDebugGui.Core.Protocol;

public sealed record DebugVariableValue(string Name, object? Value, DateTime TimestampUtc);
