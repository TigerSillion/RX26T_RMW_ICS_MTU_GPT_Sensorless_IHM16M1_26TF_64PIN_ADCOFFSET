using System.Text.Json;

namespace PcDebugGui.Core.Sessions;

public sealed class JsonSessionTemplateStore : ISessionTemplateStore
{
    private static readonly JsonSerializerOptions SerializerOptions = new()
    {
        WriteIndented = true,
    };

    private readonly string _sessionFolder;

    public JsonSessionTemplateStore(string sessionFolder)
    {
        _sessionFolder = sessionFolder;
        Directory.CreateDirectory(_sessionFolder);
    }

    public async Task<IReadOnlyList<SessionTemplate>> LoadAllAsync(CancellationToken cancellationToken = default)
    {
        var files = Directory.GetFiles(_sessionFolder, "*.json", SearchOption.TopDirectoryOnly);
        var list = new List<SessionTemplate>(files.Length);

        foreach (var file in files)
        {
            await using var stream = File.OpenRead(file);
            var template = await JsonSerializer.DeserializeAsync<SessionTemplate>(stream, SerializerOptions, cancellationToken);
            if (template is not null)
            {
                list.Add(template);
            }
        }

        return list.OrderByDescending(item => item.SavedAtUtc).ToArray();
    }

    public async Task SaveAsync(SessionTemplate template, CancellationToken cancellationToken = default)
    {
        var safeName = string.Join("_", template.Name.Split(Path.GetInvalidFileNameChars(), StringSplitOptions.RemoveEmptyEntries));
        var fullPath = Path.Combine(_sessionFolder, $"{safeName}_{DateTime.UtcNow:yyyyMMdd_HHmmss}.json");

        await using var stream = File.Create(fullPath);
        await JsonSerializer.SerializeAsync(stream, template, SerializerOptions, cancellationToken);
    }
}
