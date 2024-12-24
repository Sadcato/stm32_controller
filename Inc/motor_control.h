/* 电机控制头文件 */
#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "stm32f1xx_hal.h"

/* 定义运行时间限制（单位：毫秒） */
#define UP_TIME_LIMIT      8000    // 上升最大时间，根据实际调整
#define DOWN_TIME_LIMIT    8000    // 下降最大时间，根据实际调整

/* 继电器控制延时定义 */
#define RELAY_SWITCH_DELAY    50    // 继电器切换延时(ms)
#define RELAY_PROTECT_TIME    500   // 继电器保护时间(ms)

typedef enum {
    MOTOR_STOP = 0,
    MOTOR_UP,
    MOTOR_DOWN
} MotorState;

void ControlMotor(MotorState state);
MotorState GetMotorState(void);
void UpdateMotorControl(void);

/* 继电器状态检测 */
uint8_t CheckRelayStatus(void);
void RelayProtection(void);

#endif 