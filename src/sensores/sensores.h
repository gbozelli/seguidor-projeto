#ifndef SENSORES_H
#define SENSORES_H

#include <Arduino.h>
#include <QTRSensors.h>

extern QTRSensors qtr;
extern uint16_t sensorValues[];

void inicializarSensores();
void lerSensoresQTR();
bool verificarLinhaPerdida();
void verificarSensorParagem();

#endif
