/* GPIO配置头文件 */
#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#include "stm32f1xx_hal.h"

/* 引脚定义 */
#define UP_BTN_PIN     GPIO_PIN_0
#define DOWN_BTN_PIN   GPIO_PIN_1
#define STOP_BTN_PIN   GPIO_PIN_2
#define RELAY1_PIN     GPIO_PIN_3
#define RELAY2_PIN     GPIO_PIN_4
#define LIMIT_UP_PIN   GPIO_PIN_5
#define LIMIT_DOWN_PIN GPIO_PIN_6
#define EMERGENCY_PIN  GPIO_PIN_7
#define CURRENT_ADC_PIN GPIO_PIN_0

/* 端口定义 */
#define BTN_GPIO_PORT  GPIOA
#define RELAY_GPIO_PORT GPIOB

void MX_GPIO_Init(void);
uint8_t ReadButton(uint16_t pin);

#endif 