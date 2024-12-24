#include "gpio_config.h"

/* GPIO初始化 */
void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* 使能时钟 */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /* 配置输入引脚 */
    GPIO_InitStruct.Pin = UP_BTN_PIN | DOWN_BTN_PIN | STOP_BTN_PIN |
                         LIMIT_UP_PIN | LIMIT_DOWN_PIN | EMERGENCY_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(BTN_GPIO_PORT, &GPIO_InitStruct);

    /* 配置继电器输出引脚 */
    GPIO_InitStruct.Pin = RELAY1_PIN | RELAY2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(RELAY_GPIO_PORT, &GPIO_InitStruct);

    /* 配置LED指示灯 */
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

/* 读取按钮状态 */
uint8_t ReadButton(uint16_t pin)
{
    return HAL_GPIO_ReadPin(BTN_GPIO_PORT, pin) == GPIO_PIN_RESET;
} 