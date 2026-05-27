#include "sensores.h"
#include "../config/config.h"
#include "../motor/motor.h"

QTRSensors qtr;
uint16_t sensorValues[SENSOR_COUNT];

void inicializarSensores()
{
  pinMode(SENSOR_PARADA, INPUT_PULLUP);
  pinMode(SENSOR_CURVA, INPUT_PULLUP);

  qtr.setTypeRC();
  qtr.setSensorPins(SENSOR_PINS, SENSOR_COUNT);

  // Calibração
  for (uint16_t i = 0; i < 200; i++)
  {
    qtr.calibrate();
    delay(10);
  }
}

void lerSensoresQTR()
{
  qtr.read(sensorValues);
}

bool verificarLinhaPerdida()
{
  for (int i = 0; i < SENSOR_COUNT; i++)
  {
    if (sensorValues[i] > 150)
    {
      return false;
    }
  }
  return true;
}

void verificarSensorParagem()
{
  int estadoSensorParada = digitalRead(SENSOR_PARADA);

  if (estadoSensorParada == LOW)
  {
    stop_count += 1;
    pararMotores();
    start = false;
  }
}
