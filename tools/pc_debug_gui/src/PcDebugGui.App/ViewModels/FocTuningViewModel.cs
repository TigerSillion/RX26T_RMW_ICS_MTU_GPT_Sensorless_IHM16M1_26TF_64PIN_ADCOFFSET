using System.Collections.ObjectModel;
using PcDebugGui.App.Models;
using PcDebugGui.Core.Models;

namespace PcDebugGui.App.ViewModels;

public sealed class FocTuningViewModel : ViewModelBase
{
    public ObservableCollection<ParameterItem> Parameters { get; } =
        new(FocParameterCatalog.Items.Select(item => new ParameterItem
        {
            Name = item.Name,
            Category = item.Category,
            Unit = item.Unit,
            Description = item.Description,
            Value = "0",
        }));

    public Dictionary<string, string> Snapshot() => Parameters.ToDictionary(item => item.Name, item => item.Value);

    public void Restore(Dictionary<string, string> snapshot)
    {
        foreach (var parameter in Parameters)
        {
            if (snapshot.TryGetValue(parameter.Name, out var value))
            {
                parameter.Value = value;
            }
        }
    }
}
