#include "motor.h"
#include "../config/config.h"

// TODO: implementar inicializarMotor()
// - configurar pinMode para os 4 pinos de motor como OUTPUT
// - usar ledcAttach para PWM nos dois pinos PWM
// - chamar pararMotores() para iniciar com motores parados

// TODO: implementar pararMotores()
// - escrever LOW em todos os pinos de motor
// - escrever 0 nos dois canais PWM com ledcWrite()

// TODO: implementar controlarMotor()
// - recebe velocidadeEsq e velocidadeDir
// - validar com constrain() entre 0 e VEL_MAX
// - escrever valores PWM com ledcWrite() nos dois canais
