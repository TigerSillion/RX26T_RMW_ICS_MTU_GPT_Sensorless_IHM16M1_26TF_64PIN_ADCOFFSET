# PC Debug GUI (Windows)

该目录提供一个可快速迭代的 Windows 桌面调试工具骨架（WPF + .NET 8），用于对接 RX26T 电机控制固件调试。

## 架构分层

1. **Transport 层**（`PcDebugGui.Core/Transport`）
   - `ITransport` 抽象收发链路。
   - 当前实现 `SerialTransport`。
   - 预留 `CAN/Ethernet` 扩展入口（`TransportKind` + `TransportFactory`）。
2. **Protocol Client 层**（`PcDebugGui.Core/Protocol`）
   - `IMcuDebugProtocolClient` 封装读写变量、采样捕获接口。
   - `McuDebugProtocolClient` 对应 MCU 调试协议客户端占位实现。
3. **UI 功能层**（`PcDebugGui.App`）
   - FOC 参数调谐页：绑定 `st_rmw_param_buffer_t` 关键字段目录。
   - 软件示波器页：多通道、触发/时基/缩放参数入口、CSV 导出预留。
   - 变量/寄存器浏览页：树结构、搜索、读写、收藏。

## 会话模板

- 存储位置：运行目录 `sessions/*.json`。
- 内容：
  - 示波器通道启用状态。
  - 变量收藏组。
  - FOC 参数快照。
- 在主窗口可执行“保存会话模板 / 恢复最近模板”。

## 快速开始

```powershell
cd tools/pc_debug_gui/src
# 用 Visual Studio 打开 PcDebugGui.sln 或命令行编译
# dotnet build PcDebugGui.sln
```

## 最小发布流程（便携版）

```powershell
cd tools/pc_debug_gui
pwsh ./scripts/publish-portable.ps1 -Runtime win-x64
```

产物位于：
`tools/pc_debug_gui/dist/win-x64/`

其中包含：
- `PcDebugGui.App.exe`
- `appsettings.json`
- `sessions/` 初始目录

> 注意：当前仓库主要为 MCU 固件工程，PC GUI 为新增桌面工具骨架，协议打包/校验细节可在 `McuDebugProtocolClient` 中按后续调试协议继续扩展。
