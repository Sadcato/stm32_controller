#include "main.h"
#include "gpio_config.h"
#include "motor_control.h"
#include "safety_check.h"

static uint32_t lastDebounceTime = 0;
const uint32_t debounceDelay = 50;

int main(void)
{
    /* 初始化代码 */
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    while (1)
    {
        /* 按钮控制逻辑 */
        if ((HAL_GetTick() - lastDebounceTime) > debounceDelay)
        {
            if (ReadButton(UP_BTN_PIN))
            {
                ControlMotor(MOTOR_UP);
                lastDebounceTime = HAL_GetTick();
            }
            else if (ReadButton(DOWN_BTN_PIN))
            {
                ControlMotor(MOTOR_DOWN);
                lastDebounceTime = HAL_GetTick();
            }
            else if (ReadButton(STOP_BTN_PIN))
            {
                ControlMotor(MOTOR_STOP);
                lastDebounceTime = HAL_GetTick();
            }
        }

        /* 更新电机控制状态 */
        UpdateMotorControl();
        
        HAL_Delay(10);
    }
} 