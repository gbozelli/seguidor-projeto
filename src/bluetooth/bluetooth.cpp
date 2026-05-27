#include "bluetooth.h"
#include "../config/config.h"
#include "../motor/motor.h"

BluetoothSerial SerialBT;

// TODO: implementar inicializarBluetooth()
// - chamar SerialBT.begin() com nome do dispositivo BT

// TODO: implementar processarComandosBT()
// - verificar se SerialBT.available()
// - ler comando até '\n'
// - se comando começa com "kp ": atualizar KP com substring e toFloat()
// - se comando começa com "kd ": atualizar KD
// - se comando começa com "vel ": atualizar VEL_MAX
// - se comando começa com "INICIA": ativar start, resetar stop_count, registrar instante_inicial
// - se comando começa com "PARA": desativar start, parar motores
