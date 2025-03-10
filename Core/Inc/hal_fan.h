#ifndef HAL_FAN_H
#define HAL_FAN_H

#include <stdint.h>

// Function to initialize fan control
void HAL_Fan_Init(void);

// Function to set fan speed (0-100%)
void HAL_Fan_SetSpeed(uint8_t speed);

#endif
