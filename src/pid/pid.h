#ifndef PID_H
#define PID_H

#include <Arduino.h>

extern uint16_t sensorValues[];

void calcularPID();
int obterPosition();

#endif
