/* 安全检查头文件 */
#ifndef SAFETY_CHECK_H
#define SAFETY_CHECK_H

#include "stm32f1xx_hal.h"

#define CURRENT_THRESHOLD 2000

/* 电源监测阈值 */
#define VOLTAGE_24V_MIN   22.0f    // 24V最小电压
#define VOLTAGE_24V_MAX   26.0f    // 24V最大电压
#define VOLTAGE_5V_MIN    4.8f     // 5V最小电压
#define VOLTAGE_5V_MAX    5.2f     // 5V最大电压

uint8_t CheckSafety(void);
uint8_t CheckLimitSwitches(void);
uint8_t CheckEmergencyStop(void);
uint16_t GetMotorCurrent(void);

/* 电源监测函数 */
uint8_t CheckPowerSupply(void);
float Get24VVoltage(void);
float Get5VVoltage(void);

#endif 