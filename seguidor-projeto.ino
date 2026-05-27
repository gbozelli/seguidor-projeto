#include <Arduino.h>
#include "src/config/config.h"
#include "src/motor/motor.h"
#include "src/sensores/sensores.h"
#include "src/bluetooth/bluetooth.h"
#include "src/pid/pid.h"

void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  inicializarMotor();
  inicializarSensores();
  inicializarBluetooth();
}

void loop()
{
  processarComandosBT();

  if (millis() - lastLoopTime < loopInterval)
  {
    return;
  }
  lastLoopTime = millis();

  lerSensoresQTR();

  linhaPerdida = verificarLinhaPerdida();

  if (linhaPerdida)
  {
    pararMotores();
    return;
  }

  if (start == true)
  {
    calcularPID();
    if (num_stops > 0)
    {
      verificarSensorParagem();
    }
  }
  else
  {
    pararMotores();
  }
}
