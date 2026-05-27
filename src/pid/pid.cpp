#include "pid.h"
#include "../config/config.h"
#include "../motor/motor.h"
#include "../sensores/sensores.h"

int obterPosition()
{
  return qtr.readLine(sensorValues);
}

void calcularPID()
{
  int position = obterPosition();
  float error = position - 3000;
  static float previousError = 0;
  float derivative = error - previousError;
  float output = KP * error + KD * derivative;
  previousError = error;

  int velocidadeEsq = VEL_MAX - output;
  int velocidadeDir = VEL_MAX + output;

  controlarMotor(velocidadeEsq, velocidadeDir);
}
