namespace PcDebugGui.Core.Sessions;

public interface ISessionTemplateStore
{
    Task<IReadOnlyList<SessionTemplate>> LoadAllAsync(CancellationToken cancellationToken = default);
    Task SaveAsync(SessionTemplate template, CancellationToken cancellationToken = default);
}
