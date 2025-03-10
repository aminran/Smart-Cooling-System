#include "smart_cooling_system.h"
#include "hal_temperature.h"
#include "hal_fan.h"

// PID Control Parameters (Adjust as needed)
#define TEMP_SETPOINT 30.0    // Desired temperature (°C)
#define Kp 1.5                // Proportional Gain
#define Ki 0.05               // Integral Gain
#define Kd 0.1                // Derivative Gain

static float last_error = 0, integral = 0;

uint8_t PID_Control(float current_temp) {
    float error = TEMP_SETPOINT - current_temp;
    integral += error;
    float derivative = error - last_error;
    last_error = error;

    // PID formula
    float control_signal = (Kp * error) + (Ki * integral) + (Kd * derivative);
    
    // Convert to fan speed (0-100%)
    if (control_signal < 0) control_signal = 0;
    if (control_signal > 100) control_signal = 100;
    
    return (uint8_t)control_signal;
}

void smartColling_Run(SmartCoolingSystem *system) {
    float temp = system->read_temperature();
    uint8_t fan_speed = PID_Control(temp);
    system->set_fan_speed(fan_speed);
    
    //printf("Temp: %.2f°C | Fan Speed: %d%%\n", temp, fan_speed);
}

void smartColling_Init(SmartCoolingSystem *system) {
    HAL_Temperature_Init();
    HAL_Fan_Init();
    
    system->read_temperature = HAL_Temperature_Read;  
    system->set_fan_speed = HAL_Fan_SetSpeed;
}
