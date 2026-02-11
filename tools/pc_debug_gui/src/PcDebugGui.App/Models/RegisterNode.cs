using System.Collections.ObjectModel;

namespace PcDebugGui.App.Models;

public sealed class RegisterNode
{
    public string Name { get; init; } = string.Empty;
    public string Address { get; init; } = string.Empty;
    public string Value { get; set; } = string.Empty;
    public bool IsFavorite { get; set; }
    public ObservableCollection<RegisterNode> Children { get; init; } = [];
}
