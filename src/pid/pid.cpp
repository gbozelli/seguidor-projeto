#include "pid.h"
#include "../config/config.h"
#include "../motor/motor.h"
#include "../sensores/sensores.h"

// TODO: implementar obterPosition()
// - chamar qtr.readLine() com sensorValues
// - retornar a posição da linha (0-6000)

// TODO: implementar calcularPID()
// - chamar obterPosition()
// - calcular erro = position - 3000 (centro)
// - usar static float previousError para calcular derivada
// - output = KP * error + KD * derivative
// - velocidadeEsq = VEL_MAX - output
// - velocidadeDir = VEL_MAX + output
// - chamar controlarMotor() com as velocidades
// - atualizar previousError para próxima iteração
