#include "sensores.h"
#include "../config/config.h"
#include "../motor/motor.h"

QTRSensors qtr;
uint16_t sensorValues[SENSOR_COUNT];

// TODO: implementar inicializarSensores()
// - configurar pinMode para sensores de parada e curva como INPUT_PULLUP
// - chamar qtr.setTypeRC()
// - passar SENSOR_PINS e SENSOR_COUNT para qtr.setSensorPins()
// - fazer 200 iterações de qtr.calibrate() com delay(10)

// TODO: implementar lerSensoresQTR()
// - chamar qtr.read() para preencher sensorValues[]

// TODO: implementar verificarLinhaPerdida()
// - iterar pelos sensorValues
// - retornar false se algum sensor > 150 (linha encontrada)
// - retornar true se nenhum sensor detectou (linha perdida)

// TODO: implementar verificarSensorParagem()
// - ler SENSOR_PARADA com digitalRead()
// - se LOW: incrementar stop_count, parar motores, parar execução
