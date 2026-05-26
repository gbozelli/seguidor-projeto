#include "ExtraDefs.h"

void initializeExtraDefinitions() {
  pinMode(LED_STATUS, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  digitalWrite(LED_STATUS, LOW);
  Serial.println("Extra definitions inicializadas");
}

void performExtraTask() {
  int sensorValue = analogRead(SENSOR_PIN);
  if (sensorValue > 512) {
    digitalWrite(LED_STATUS, HIGH);
  } else {
    digitalWrite(LED_STATUS, LOW);
  }
}
