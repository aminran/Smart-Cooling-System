#ifndef HAL_TEMPERATURE_H
#define HAL_TEMPERATURE_H

#include <stdint.h>

// Function to initialize the temperature sensor
void HAL_Temperature_Init(void);

// Function to read temperature from the sensor
float HAL_Temperature_Read(void);

#endif