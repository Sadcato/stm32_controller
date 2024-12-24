/* 主程序头文件 */
#ifndef MAIN_H
#define MAIN_H

#include "stm32f1xx_hal.h"
#include "gpio_config.h"
#include "motor_control.h"
#include "safety_check.h"
#include "system_config.h"

void SystemClock_Config(void);
void Error_Handler(void);

#endif 