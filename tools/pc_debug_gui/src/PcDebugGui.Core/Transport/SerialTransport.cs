using System.IO.Ports;

namespace PcDebugGui.Core.Transport;

public sealed class SerialTransport : ITransport
{
    private readonly SerialPort _serialPort;

    public SerialTransport(SerialTransportOptions options)
    {
        _serialPort = new SerialPort(options.PortName, options.BaudRate)
        {
            DataBits = options.DataBits,
            StopBits = options.StopBits switch
            {
                2 => StopBits.Two,
                _ => StopBits.One,
            },
            Parity = options.Parity.Equals("Even", StringComparison.OrdinalIgnoreCase) ? Parity.Even : Parity.None,
            ReadTimeout = 100,
            WriteTimeout = 100,
        };
    }

    public string Name => $"Serial:{_serialPort.PortName}";

    public bool IsConnected => _serialPort.IsOpen;

    public Task ConnectAsync(CancellationToken cancellationToken = default)
    {
        _serialPort.Open();
        return Task.CompletedTask;
    }

    public Task DisconnectAsync(CancellationToken cancellationToken = default)
    {
        if (_serialPort.IsOpen)
        {
            _serialPort.Close();
        }

        return Task.CompletedTask;
    }

    public Task<int> SendAsync(ReadOnlyMemory<byte> payload, CancellationToken cancellationToken = default)
    {
        _serialPort.Write(payload.Span);
        return Task.FromResult(payload.Length);
    }

    public Task<int> ReceiveAsync(Memory<byte> buffer, CancellationToken cancellationToken = default)
    {
        var count = _serialPort.Read(buffer.Span);
        return Task.FromResult(count);
    }

    public ValueTask DisposeAsync()
    {
        _serialPort.Dispose();
        return ValueTask.CompletedTask;
    }
}
