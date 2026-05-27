#include "motor.h"
#include "../config/config.h"

void inicializarMotor()
{
  for (int i = 0; i < 4; i++)
  {
    pinMode(MOTOR_PINS[i], OUTPUT);
  }

  ledcAttach(PWM_PINS[0], 5000, 8);
  ledcAttach(PWM_PINS[1], 5000, 8);

  pararMotores();
}

void pararMotores()
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(MOTOR_PINS[i], LOW);
  }
  ledcWrite(0, 0);
  ledcWrite(1, 0);
}

void controlarMotor(int velocidadeEsq, int velocidadeDir)
{
  velocidadeEsq = constrain(velocidadeEsq, 0, VEL_MAX);
  velocidadeDir = constrain(velocidadeDir, 0, VEL_MAX);

  ledcWrite(0, velocidadeEsq);
  ledcWrite(1, velocidadeDir);
}
