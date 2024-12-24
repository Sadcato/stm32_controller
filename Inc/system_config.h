/* 系统配置头文件 */
#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include "stm32f1xx_hal.h"

/* 系统参数定义 */
#define SYSTEM_TICK_MS     10      // 系统基本时间片
#define DEBOUNCE_TIME_MS   50      // 按键消抖时间
#define MOTOR_TIMEOUT_MS   30000   // 电机运行超时时间

/* 系统状态枚举 */
typedef enum {
    SYSTEM_NORMAL = 0,
    SYSTEM_ERROR,
    SYSTEM_EMERGENCY
} SystemState;

void SystemConfig_Init(void);
SystemState GetSystemState(void);
void SetSystemState(SystemState state);
void SystemError_Handler(uint8_t error_code);

#endif 