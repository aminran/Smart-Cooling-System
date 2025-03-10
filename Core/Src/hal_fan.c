#include "hal_fan.h"
#include "stm32f1xx_hal.h"

TIM_HandleTypeDef htim1; // Timer for PWM control

void HAL_Fan_Init(void) {
    // Configure Timer PWM for fan control (HAL_TIM_PWM_Init)
}

void HAL_Fan_SetSpeed(uint8_t speed) {
  TIM1->CCR1 = speed;
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}
