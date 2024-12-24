#include "system_config.h"

static SystemState currentSystemState = SYSTEM_NORMAL;

/* 系统配置初始化 */
void SystemConfig_Init(void)
{
    // 初始化系统时钟
    SystemClock_Config();
    
    // 初始化外设
    MX_GPIO_Init();
    MX_ADC1_Init();
    
    // 启动看门狗（如果需要）
    // MX_IWDG_Init();
    
    currentSystemState = SYSTEM_NORMAL;
}

/* 获取系统状态 */
SystemState GetSystemState(void)
{
    return currentSystemState;
}

/* 设置系统状态 */
void SetSystemState(SystemState state)
{
    currentSystemState = state;
}

/* 系统错误处理 */
void SystemError_Handler(uint8_t error_code)
{
    SetSystemState(SYSTEM_ERROR);
    
    // 停止电机
    ControlMotor(MOTOR_STOP);
    
    // 这里可以添加错误指示，如LED闪烁等
    while (1)
    {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);  // 假设PC13连接了LED
        HAL_Delay(500);
    }
} 