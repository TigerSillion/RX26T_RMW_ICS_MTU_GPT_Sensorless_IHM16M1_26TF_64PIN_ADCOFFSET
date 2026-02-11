using System.Windows;

namespace PcDebugGui.App.Services;

public sealed class DialogNotificationService : INotificationService
{
    public void Info(string message) => MessageBox.Show(message, "PC Debug GUI", MessageBoxButton.OK, MessageBoxImage.Information);

    public void Error(string message) => MessageBox.Show(message, "PC Debug GUI", MessageBoxButton.OK, MessageBoxImage.Error);
}
