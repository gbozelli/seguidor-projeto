
#include <Arduino.h>
#include <QTRSensors.h>
#include "BluetoothSerial.h"

const int LED_PIN = 22;
const int SENSOR_PARADA = 23;
const int SENSOR_CURVA = 20;
const int PWM_PINS[] = {21, 2};
const int MOTOR_PINS[] = {18, 19, 5, 4};
const int SENSOR_COUNT = 7;
const uint8_t SENSOR_PINS[SENSOR_COUNT] = {13, 14, 27, 26, 25, 33, 32};

QTRSensors qtr;
uint16_t sensorValues[SENSOR_COUNT];
BluetoothSerial SerialBT;

float KP = 0.5;
float KD = 0.4;
int VEL_MAX = 80;
bool start = false;
bool linhaPerdida = false;
int stop_count = 0;
int num_stops = 2;
int instante_inicial = 0;
int timer_parada = 60000;

unsigned long lastLoopTime = 0;
const unsigned long loopInterval = 30;

void pararMotores()
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(MOTOR_PINS[i], LOW);
  }
  ledcWrite(0, 0);
  ledcWrite(1, 0);
}

void setup()
{
  Serial.begin(115200);
  SerialBT.begin("XerapoBT");

  pinMode(LED_PIN, OUTPUT);
  pinMode(SENSOR_PARADA, INPUT_PULLUP);
  pinMode(SENSOR_CURVA, INPUT_PULLUP);

  for (int i = 0; i < 4; i++)
  {
    pinMode(MOTOR_PINS[i], OUTPUT);
  }

  qtr.setTypeRC();
  qtr.setSensorPins(SENSOR_PINS, SENSOR_COUNT);
  for (uint16_t i = 0; i < 200; i++)
  {
    qtr.calibrate();
    delay(10);
  }

  ledcAttach(PWM_PINS[0], 5000, 8);
  ledcAttach(PWM_PINS[1], 5000, 8);

  pararMotores();
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

void sensorParagem()
{
  int estadoSensorParada = digitalRead(SENSOR_PARADA);

  if (estadoSensorParada == LOW)
  {
    stop_count += 1;
    pararMotores();
    start = false;
  }
}

void calcularPID()
{
  int position = qtr.readLine(sensorValues);
  float error = position - 3000;
  static float previousError = 0;
  float derivative = error - previousError;
  float output = KP * error + KD * derivative;
  previousError = error;

  int velocidadeEsq = VEL_MAX - output;
  int velocidadeDir = VEL_MAX + output;

  velocidadeEsq = constrain(velocidadeEsq, 0, VEL_MAX);
  velocidadeDir = constrain(velocidadeDir, 0, VEL_MAX);

  ledcWrite(0, velocidadeEsq);
  ledcWrite(1, velocidadeDir);
}

void loop()
{
  processarComandosBT();

  if (millis() - lastLoopTime < loopInterval)
  {
    return;
  }
  lastLoopTime = millis();

  qtr.read(sensorValues);

  linhaPerdida = true;
  for (int i = 0; i < SENSOR_COUNT; i++)
  {
    if (sensorValues[i] > 150)
    {
      linhaPerdida = false;
      break;
    }
  }

  if (linhaPerdida)
  {
    pararMotores();
    return;
  }

  if (start == true)
  {
    calcularPID();
    if (num_stops > 0)
    {
      sensorParagem();
    }
  }
  else
  {
    pararMotores();
  }
}
