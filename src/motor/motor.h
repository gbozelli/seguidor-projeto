#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

void inicializarMotor();
void pararMotores();
void controlarMotor(int velocidadeEsq, int velocidadeDir);

#endif
