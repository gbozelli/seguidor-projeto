#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "BluetoothSerial.h"

extern BluetoothSerial SerialBT;

void inicializarBluetooth();
void processarComandosBT();

#endif
