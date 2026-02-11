# RMW Debug Protocol (v1)

本文档定义 `app/rmw/debug_proto/` 实现的串口调试协议，供 PC GUI 与自动化脚本共用。

## 1. 帧格式

| 字段 | 字节数 | 说明 |
|---|---:|---|
| SOF0 | 1 | 固定 `0x55` |
| SOF1 | 1 | 固定 `0xAA` |
| Version | 1 | 协议版本，当前 `0x01` |
| Sequence | 1 | 序号，主机发起请求时递增，设备响应回显 |
| Command | 1 | 命令字 |
| Error | 1 | 错误码（请求中置 0；响应/上报中返回状态） |
| Length | 2 | Payload 长度，Little Endian |
| Payload | N | 负载，`0~128` 字节 |
| CRC16 | 2 | 对 `Version..Payload` 计算 CRC16(Modbus，多项式 0xA001，初值 0xFFFF) |

> 预留：通过 `Version` 字段实现向后兼容扩展。

## 2. 错误码

- `0x00`：成功
- `0x01`：不支持的命令
- `0x02`：长度不合法
- `0x03`：CRC 错误
- `0x04`：变量 ID 不存在/不可访问
- `0x05`：变量只读
- `0x7F`：内部错误

## 3. 命令定义

- `0x01 GET_PROTOCOL_INFO`：查询协议版本与能力位
- `0x10 READ_VAR`：单变量读取
- `0x11 WRITE_VAR`：单变量写入
- `0x12 READ_VAR_BATCH`：批量读取
- `0x13 WRITE_VAR_BATCH`：批量写入
- `0x20 STREAM_CONFIG`：连续采样通道配置
- `0x21 STREAM_SAMPLE`：连续采样上报（设备主动）

## 4. 变量访问编码

### 4.1 单变量读 `0x10`

请求 Payload：`var_id_le16`

响应 Payload：`var_id_le16 | size_u8 | raw_bytes`

### 4.2 单变量写 `0x11`

请求 Payload：`var_id_le16 | size_u8 | raw_bytes`

响应 Payload：空（通过 Error 指示结果）

### 4.3 批量读 `0x12`

请求 Payload：`count_u8 | var_id_le16 * count`

响应 Payload：`count_u8 | [var_id_le16 | size_u8 | raw_bytes] * count`

### 4.4 批量写 `0x13`

请求 Payload：`count_u8 | [var_id_le16 | size_u8 | raw_bytes] * count`

响应 Payload：空

## 5. 连续采样

### 5.1 配置命令 `0x20`

请求 Payload：

- `enable_u8`：`0` 关闭，`1` 开启
- `interval_u8`：采样间隔（以 `r_app_rmw_interrupt_handler()` 调用周期计）
- `channel_count_u8`：通道数，最大 8
- `var_id_le16 * channel_count`

响应 Payload：回显同上配置。

### 5.2 采样上报 `0x21`

Payload：`[var_id_le16 | size_u8 | raw_bytes] * channel_count`

## 6. 节流策略

原有 `ICS_DECIMATION` 被保留为默认值，并映射为可写变量 `0x0200 (ICS_DECIMATION)`。
上位机可通过 `WRITE_VAR/WRITE_VAR_BATCH` 动态调整，不再硬编码。

## 7. 当前变量 ID（v1）

- `0x0001` `com_u1_system_mode` (u8)
- `0x0002` `com_u1_enable_write` (u8)
- `0x0101` `com_f4_ref_speed_rpm` (f32)
- `0x0102` `com_u1_ctrl_loop_mode` (u8)
- `0x0103` `com_f4_current_omega_hz` (f32)
- `0x0104` `com_f4_speed_omega_hz` (f32)
- `0x0200` `g_u1_ics_decimation` (u8)

> 后续扩展原则：新增变量 ID 不重用旧 ID；删除变量时保留 ID 并返回 `BAD_VAR`。
