#include "safety_check.h"
#include "gpio_config.h"
#include "motor_control.h"
#include "system_config.h"

/* 安全检查函数 */
uint8_t CheckSafety(void)
{
    // 检查紧急停止
    if (!CheckEmergencyStop())
        return 0;
    
    // 检查限位开关
    if (!CheckLimitSwitches())
        return 0;
    
    // 检查电流
    if (GetMotorCurrent() > CURRENT_THRESHOLD)
        return 0;
        
    return 1;
}

/* 限位开关检查 */
uint8_t CheckLimitSwitches(void)
{
    MotorState currentState = GetMotorState();
    
    // 上限位检查
    if (currentState == MOTOR_UP && 
        HAL_GPIO_ReadPin(BTN_GPIO_PORT, LIMIT_UP_PIN) == GPIO_PIN_SET)
        return 0;
    
    // 下限位检查
    if (currentState == MOTOR_DOWN && 
        HAL_GPIO_ReadPin(BTN_GPIO_PORT, LIMIT_DOWN_PIN) == GPIO_PIN_SET)
        return 0;
        
    return 1;
}

/* 紧急停止检查 */
uint8_t CheckEmergencyStop(void)
{
    return (HAL_GPIO_ReadPin(BTN_GPIO_PORT, EMERGENCY_PIN) == GPIO_PIN_RESET);
}

/* 获取电机电流 */
uint16_t GetMotorCurrent(void)
{
    // 读取ADC值并返回
    return HAL_ADC_GetValue(&hadc1);
} 