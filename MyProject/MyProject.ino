#include <Arduino.h>
#include "src/MyFunctions.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("MyProject iniciando...");
  
  initializeSystem();
}

void loop() {
  doWork();
  delay(100);
}
