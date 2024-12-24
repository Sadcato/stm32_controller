#include "motor_control.h"
#include "gpio_config.h"

static MotorState currentState = MOTOR_STOP;
static uint32_t startTime = 0;

void ControlMotor(MotorState state)
{
    switch (state)
    {
        case MOTOR_UP:
            HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY1_PIN, GPIO_PIN_SET);
            HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY2_PIN, GPIO_PIN_RESET);
            if (currentState != MOTOR_UP) {
                startTime = HAL_GetTick();  // 记录开始时间
            }
            break;
            
        case MOTOR_DOWN:
            HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY1_PIN, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY2_PIN, GPIO_PIN_SET);
            if (currentState != MOTOR_DOWN) {
                startTime = HAL_GetTick();  // 记录开始时间
            }
            break;
            
        case MOTOR_STOP:
        default:
            HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY1_PIN, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY2_PIN, GPIO_PIN_RESET);
            break;
    }
    
    currentState = state;
}

void UpdateMotorControl(void)
{
    uint32_t currentTime = HAL_GetTick();
    uint32_t runTime = currentTime - startTime;

    // 检查是否达到时间限制
    if (currentState == MOTOR_UP && runTime >= UP_TIME_LIMIT) {
        ControlMotor(MOTOR_STOP);  // 达到上升时间限制，停止
    }
    else if (currentState == MOTOR_DOWN && runTime >= DOWN_TIME_LIMIT) {
        ControlMotor(MOTOR_STOP);  // 达到下降时间限制，停止
    }
}

MotorState GetMotorState(void)
{
    return currentState;
} 