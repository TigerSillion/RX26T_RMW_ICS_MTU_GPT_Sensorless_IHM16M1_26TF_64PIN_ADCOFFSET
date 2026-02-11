using PcDebugGui.Core.Transport;

namespace PcDebugGui.Core.Protocol;

public sealed class McuDebugProtocolClient : IMcuDebugProtocolClient
{
    private readonly ITransport _transport;

    public McuDebugProtocolClient(ITransport transport)
    {
        _transport = transport;
    }

    public Task ConnectAsync(CancellationToken cancellationToken = default) => _transport.ConnectAsync(cancellationToken);

    public Task DisconnectAsync(CancellationToken cancellationToken = default) => _transport.DisconnectAsync(cancellationToken);

    public Task<IDictionary<string, object?>> ReadVariablesAsync(IReadOnlyCollection<string> names, CancellationToken cancellationToken = default)
    {
        IDictionary<string, object?> snapshot = names.ToDictionary(key => key, key => (object?)$"TODO:{key}");
        return Task.FromResult(snapshot);
    }

    public Task WriteVariablesAsync(IReadOnlyDictionary<string, object?> values, CancellationToken cancellationToken = default)
    {
        return Task.CompletedTask;
    }

    public Task<DebugVariableValue[]> CaptureSamplesAsync(IReadOnlyList<string> channels, int sampleCount, CancellationToken cancellationToken = default)
    {
        var now = DateTime.UtcNow;
        var samples = channels
            .SelectMany(channel => Enumerable.Range(0, sampleCount).Select(index => new DebugVariableValue(channel, Math.Sin(index / 10.0), now.AddMilliseconds(index))))
            .ToArray();

        return Task.FromResult(samples);
    }
}
