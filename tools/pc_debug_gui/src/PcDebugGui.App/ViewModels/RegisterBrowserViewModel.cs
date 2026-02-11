using System.Collections.ObjectModel;
using PcDebugGui.App.Models;

namespace PcDebugGui.App.ViewModels;

public sealed class RegisterBrowserViewModel : ViewModelBase
{
    public ObservableCollection<RegisterNode> RegisterTree { get; } =
    [
        new RegisterNode
        {
            Name = "MotorControl",
            Address = "0x4000",
            Children =
            [
                new RegisterNode { Name = "IqRef", Address = "0x4001", Value = "0.0" },
                new RegisterNode { Name = "IdRef", Address = "0x4002", Value = "0.0" },
                new RegisterNode { Name = "SpeedRef", Address = "0x4003", Value = "1500" },
            ],
        },
        new RegisterNode
        {
            Name = "Observer",
            Address = "0x4100",
            Children =
            [
                new RegisterNode { Name = "PhaseErr", Address = "0x4101", Value = "0.0" },
                new RegisterNode { Name = "BemfEst", Address = "0x4102", Value = "0.0" },
            ],
        },
    ];

    private string _searchText = string.Empty;

    public string SearchText
    {
        get => _searchText;
        set => SetProperty(ref _searchText, value);
    }

    public IEnumerable<RegisterNode> Favorites => RegisterTree.SelectMany(Flatten).Where(node => node.IsFavorite);

    public IReadOnlyList<string> SnapshotFavoriteVariables() => Favorites.Select(item => item.Name).ToArray();

    public void RestoreFavorites(IEnumerable<string> favorites)
    {
        var set = favorites.ToHashSet(StringComparer.OrdinalIgnoreCase);
        foreach (var node in RegisterTree.SelectMany(Flatten))
        {
            node.IsFavorite = set.Contains(node.Name);
        }
    }

    private static IEnumerable<RegisterNode> Flatten(RegisterNode node)
    {
        yield return node;
        foreach (var child in node.Children)
        {
            foreach (var nested in Flatten(child))
            {
                yield return nested;
            }
        }
    }
}
