# AUTOSAR COM 模块发送模式详解

## 1. 核心概念：Signal 与 I-PDU
在 AUTOSAR COM 模块中，**Signal（信号）** 是数据的最小单位，而 **I-PDU（交互层协议数据单元）** 是承载这些数据在网络上传送的“数据帧”。

将二者的关系类比为“**乘客（Signal）**”和“**班车（I-PDU）**”的运营规则，有助于理解其复杂的工作机制。

---

## 2. Signal 的发送属性（Transfer Property）
该属性（`ComTransferProperty`）定义了当上层应用（RTE）调用 `Com_SendSignal()` 更新信号值时，以何种方式触发所属 I-PDU 的发送。

| 属性值 | 行为描述 | 类比 |
| :--- | :--- | :--- |
| **PENDING（延迟）** | 信号值被更新，但**不会**触发 I-PDU 发送。仅等待下一次周期发送。 | 不着急的“慢性子”乘客，上车后安静等待班车按计划发车。 |
| **TRIGGERED（触发）** | 信号值更新后**立即触发** I-PDU 发送（可配置重复发送 N 次）。 | 着急的乘客，一上车就催司机立刻发车。 |
| **TRIGGERED_ON_CHANGE** | 信号值**发生变化时**才立即触发发送（可配置重复发送 N 次）。 | 只有带新消息的“急性子”乘客才触发发车。 |
| **带 WITHOUT_REPETITION 变体** | 触发后**只发送一次**，不重复发送。 | 叫了车，但只坐一班，不要求加开多班。 |

---

## 3. I-PDU 的发送模式（Transmission Mode）
该属性（`ComTxModeMode`）定义了 I-PDU 本身的调度策略。

| 模式 | 行为描述 | 类比 |
| :--- | :--- | :--- |
| **PERIODIC（周期）** | 以固定时间间隔周期性地发送，无论信号是否更新。 | 固定时间表的班车，定时发车。 |
| **DIRECT（直接/事件）** | 只在 Signal 发出“触发”请求时发送。 | 按需叫车，无请求不发车。 |
| **MIXED（混合）** | 平时按周期发送；当 Signal 触发时，加开 N 次额外发送，之后恢复周期。 | 有固定班次，也接受临时加车。 |
| **NONE（无）** | 自身不主动触发发送，由下层模块（如 PduR）通过回调函数“索取”数据。 | 停运班车，只接受外部的取货请求。 |

---

## 4. 动态决策：TMS 与 TMC 机制
每个 I-PDU 可以配置两套发送参数（`ComTxModeTrue` 和 `ComTxModeFalse`），并根据内部信号的状态动态选择其中一套生效。

- **TMC（Transmission Mode Condition）**：每个参与决策的 Signal 的条件结果（True/False），由过滤器（如值等于某阈值）决定。
- **TMS（Transmission Mode Selector）**：I-PDU 的最终选择结果。
  - **计算逻辑为“或”**：只要**任意一个** Signal 的 TMC 为 `TRUE`，则 TMS 为 `TRUE`。
  - 否则（所有 TMC 均为 `FALSE`），TMS 为 `FALSE`。

| TMS 值 | 生效的发送计划 | 典型场景 |
| :--- | :--- | :--- |
| **TRUE** | 使用 `ComTxModeTrue` 配置（如 `DIRECT` 模式） | 信号值满足特定条件（如车速超阈值），需立即上报。 |
| **FALSE** | 使用 `ComTxModeFalse` 配置（如 `PERIODIC` 模式） | 信号值在常规范围内，仅需周期上报。 |

---

## 5. 协同工作总览
下表展示了 Signal 发送属性与 I-PDU 发送模式组合后的实际行为：

| I-PDU 模式 ↓ / Signal 属性 → | **TRIGGERED（触发）** | **PENDING（延迟）** |
| :--- | :--- | :--- |
| **PERIODIC（周期）** | **周期发送**：信号更新不触发立即发送，跟随固定周期发出。 | **周期发送**：信号更新不触发发送，等待下次定时。 |
| **DIRECT（直接）** | **事件发送**：信号更新立即触发发送（可重复 N 次）。 | **从不发送**（无效组合）：无可触发源，且自身不主动发车。 |
| **MIXED（混合）** | **事件 + 周期**：平时周期发车；信号更新时额外触发 N 次快速发送。 | **周期发送**：信号更新不触发额外发送。 |
| **NONE（无）** | **不主动发送**：等待下层通过 `Com_TriggerTransmit()` 请求。 | **不主动发送**：等待下层请求。 |

---

## 6. 实际发送流程
一次完整的发送过程包含以下步骤：

1. **应用层调用**：RTE 调用 `Com_SendSignal(SignalId, DataPtr)`。
2. **数据打包**：COM 模块对信号值进行字节序转换、符号扩展等操作，并更新到所属 I-PDU 的缓冲区中，同时设置相应的更新位（Update Bits）。
3. **模式仲裁与发送**：
   - 检查 Signal 属性及 I-PDU 当前模式（或通过 TMS 计算得出）。
   - 若判断需立即发送（如 DIRECT 模式下的 TRIGGERED 信号），则调用 `PduR_ComTransmit(PduIdPtr)` 将 I-PDU 交给下层（PDU Router）。
   - 若为周期发送，则等待定时器触发。
4. **发送确认**：
   - I-PDU 发送完成后，下层通过 `Com_TxConfirmation(PduId, Result)` 回调通知 COM 模块。
   - COM 模块借此进行发送死线监控（Tx Deadline Monitoring）等后续操作。

---

## 7. 配置与使用建议
| 场景 | 推荐配置组合 |
| :--- | :--- |
| **周期性状态信号**（如车速、转速） | Signal = `PENDING` + I-PDU = `PERIODIC` |
| **事件型触发信号**（如故障报警） | Signal = `TRIGGERED` + I-PDU = `DIRECT` 或 `MIXED` |
| **需快速响应的变化信号**（如开关量） | Signal = `TRIGGERED_ON_CHANGE` + I-PDU = `DIRECT` 或 `MIXED` |
| **低功耗/轮询模式** | I-PDU = `NONE`，结合下层 `Com_TriggerTransmit()` 按需取数 |

---

## 8. 总结
- Signal 的 **发送属性** 定义了“何时触发”。
- I-PDU 的 **发送模式** 定义了“如何调度”。
- 通过 **TMS/TMC 动态机制**，可实现信号状态驱动的灵活发送策略。
- 合理组合上述配置，可以在**实时性**与**总线负载**之间取得平衡。
