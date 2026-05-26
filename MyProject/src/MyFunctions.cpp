#include "MyFunctions.h"

void initializeSystem() {
  Serial.println("Sistema inicializado");
  initializeExtraDefinitions();
}

void doWork() {
  debugPrint("Trabalhando...");
  performExtraTask();
}

void debugPrint(const char* message) {
  Serial.print("[DEBUG] ");
  Serial.println(message);
}
