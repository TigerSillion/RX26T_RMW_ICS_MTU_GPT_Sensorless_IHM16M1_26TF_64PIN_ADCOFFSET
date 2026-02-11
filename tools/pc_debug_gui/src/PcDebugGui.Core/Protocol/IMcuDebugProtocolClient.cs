namespace PcDebugGui.Core.Protocol;

public interface IMcuDebugProtocolClient
{
    Task ConnectAsync(CancellationToken cancellationToken = default);
    Task DisconnectAsync(CancellationToken cancellationToken = default);
    Task<IDictionary<string, object?>> ReadVariablesAsync(IReadOnlyCollection<string> names, CancellationToken cancellationToken = default);
    Task WriteVariablesAsync(IReadOnlyDictionary<string, object?> values, CancellationToken cancellationToken = default);
    Task<DebugVariableValue[]> CaptureSamplesAsync(IReadOnlyList<string> channels, int sampleCount, CancellationToken cancellationToken = default);
}
