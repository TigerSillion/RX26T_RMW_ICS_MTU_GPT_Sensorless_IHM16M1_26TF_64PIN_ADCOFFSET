namespace PcDebugGui.App.Services;

public interface INotificationService
{
    void Info(string message);
    void Error(string message);
}
