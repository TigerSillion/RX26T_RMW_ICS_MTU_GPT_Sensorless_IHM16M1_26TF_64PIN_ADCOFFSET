namespace PcDebugGui.Core.Transport;

public sealed record SerialTransportOptions(string PortName, int BaudRate, int DataBits = 8, int StopBits = 1, string Parity = "None");
