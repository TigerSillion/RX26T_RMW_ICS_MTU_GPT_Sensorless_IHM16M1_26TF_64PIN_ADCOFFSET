namespace PcDebugGui.Core.Transport;

public static class TransportFactory
{
    public static ITransport CreateSerial(SerialTransportOptions options) => new SerialTransport(options);

    public static ITransport Create(TransportKind kind, object options)
    {
        return kind switch
        {
            TransportKind.Serial when options is SerialTransportOptions serialOptions => new SerialTransport(serialOptions),
            TransportKind.Can => throw new NotSupportedException("CAN transport is reserved for a future protocol adapter."),
            TransportKind.Ethernet => throw new NotSupportedException("Ethernet transport is reserved for a future protocol adapter."),
            _ => throw new ArgumentException("Invalid transport configuration.", nameof(options)),
        };
    }
}
