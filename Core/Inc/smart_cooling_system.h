#ifndef SMART_COOLING_SYSTEM_H
#define SMART_COOLING_SYSTEM_H

#include <stdint.h>

typedef struct {
		float (*read_temperature)(void);  //pointer to read temperator function
		void (*set_fan_speed)(uint8_t);
}SmartCoolingSystem;

void smartColling_Init(SmartCoolingSystem *system);
void smartColling_Run(SmartCoolingSystem *system);

//PID control
uint8_t PID_Control(float current_temp);
#endif
