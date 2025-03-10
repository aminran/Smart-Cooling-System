#include "hal_temperature.h"
#include "stm32f1xx_hal.h"

ADC_HandleTypeDef hadc1;

void HAL_Temperature_Init(void) {
	
	
}

float HAL_Temperature_Read(void){
	    HAL_ADC_Start(&hadc1);
      HAL_ADC_PollForConversion(&hadc1, 100);
      uint32_t adc_value = HAL_ADC_GetValue(&hadc1);
    
      // Convert ADC value to temperature (assuming LM35 sensor)
     return ((float)adc_value * 3.3 / 4096.0) * 100.0;	 
}