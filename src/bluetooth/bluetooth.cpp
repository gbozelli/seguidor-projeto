#include "bluetooth.h"
#include "../config/config.h"
#include "../motor/motor.h"

BluetoothSerial SerialBT;

void inicializarBluetooth()
{
  SerialBT.begin("XerapoBT");
}

void processarComandosBT()
{
  if (SerialBT.available())
  {
    String comando = SerialBT.readStringUntil('\n');
    comando.trim();

    if (comando.startsWith("kp "))
    {
      KP = comando.substring(3).toFloat();
    }
    else if (comando.startsWith("kd "))
    {
      KD = comando.substring(3).toFloat();
    }
    else if (comando.startsWith("vel "))
    {
      VEL_MAX = comando.substring(4).toInt();
    }
    else if (comando.startsWith("INICIA"))
    {
      start = true;
      stop_count = 0;
      instante_inicial = millis();
    }
    else if (comando.startsWith("PARA"))
    {
      start = false;
      pararMotores();
    }
  }
}
