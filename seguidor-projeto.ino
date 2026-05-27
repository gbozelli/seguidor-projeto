#include <Arduino.h>
// TODO: incluir todos os headers dos módulos
// - config.h
// - motor.h
// - sensores.h
// - bluetooth.h
// - pid.h

void setup()
{
  // TODO: inicializar Serial com 115200
  // TODO: configurar LED_PIN como OUTPUT
  // TODO: chamar funções de inicialização de cada módulo
}

void loop()
{
  // TODO: processar comandos BT continuamente
  
  // TODO: verificar timing com millis() - não usar delay()
  // TODO: ler sensores QTR
  
  // TODO: verificar se linha foi perdida
  // - se sim: parar motores e retornar
  
  // TODO: se start == true
  // - calcular PID
  // - verificar sensor de parada se num_stops > 0
  // - senão: parar motores
}
