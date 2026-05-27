#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Pinos
const int LED_PIN = 22;
const int SENSOR_PARADA = 23;
const int SENSOR_CURVA = 20;
const int PWM_PINS[] = {21, 2};
const int MOTOR_PINS[] = {18, 19, 5, 4};
const int SENSOR_COUNT = 7;
const uint8_t SENSOR_PINS[SENSOR_COUNT] = {13, 14, 27, 26, 25, 33, 32};

// Parâmetros PID
float KP = 0.5;
float KD = 0.4;

// Velocidade
int VEL_MAX = 80;

// Estados
bool start = false;
bool linhaPerdida = false;

// Contadores
int stop_count = 0;
int num_stops = 2;
int instante_inicial = 0;
const int timer_parada = 60000;

// Timing
unsigned long lastLoopTime = 0;
const unsigned long loopInterval = 30;

#endif
