#include "variables.h"
#include <QTRSensors.h>
const int frecuencia = 5000;
const int resolucion = 8;
QTRSensors sigueLineas;
const uint8_t SensorCount = 8;
uint16_t sensorValues [SensorCount];
int contador = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinB2  , OUTPUT);
  pinMode(pinB1  , OUTPUT);
  ledcSetup(1, frecuencia, resolucion);
  ledcAttachPin(PWMB, 1);
  pinMode(pinA1  , OUTPUT);
  pinMode(pinA2 , OUTPUT);
  ledcSetup(0, frecuencia, resolucion);
  ledcAttachPin(PWMA, 0);

  Serial.begin(9600);
  sigueLineas.setTypeAnalog();

  sigueLineas.setSensorPins((const uint8_t[])
  {
    36, 39, 34, 35, 32, 33, 25, 26
  }, SensorCount);

  sigueLineas.setEmitterPin(27);
}

void loop() {
  // put your main code here, to run repeatedly:
  sigueLineas.read(sensorValues);

  for (int i = 1; i < 7 ; i++) {
    Serial.print(sensorValues[i]);
    Serial.println(i);
  }
  if (sensorValues[0] < 3000 && sensorValues[1] < 3000 && sensorValues[2] < 3000 && sensorValues[3] > 3500 && sensorValues[4] > 3500 && sensorValues[5] < 3000 && sensorValues[6] < 3500 && sensorValues[7] < 3500) {
    front(100);
  }
  else if (sensorValues[0] < 3000 && sensorValues[1] < 3000 && sensorValues[2] > 3000 && sensorValues[3] > 3500 && sensorValues[4] < 3500 && sensorValues[5] < 3000 && sensorValues[6] < 3500 && sensorValues[7] < 3500) {
    izq(100);
  }
  else if (sensorValues[0] < 3000 && sensorValues[1] < 3000 && sensorValues[2] < 3000 && sensorValues[3] < 3500 && sensorValues[4] > 3500 && sensorValues[5] > 3000 && sensorValues[6] < 3500 && sensorValues[7] < 3500) {
    der(100);
  }
  else if (sensorValues[0] < 3000 && sensorValues[1] < 3000 && sensorValues[2] < 3000 && sensorValues[3] < 3500 && sensorValues[4] > 3500 && sensorValues[5] > 3000 && sensorValues[6] > 3500 && sensorValues[7] > 3500) {
    der(100);
    Serial.println ("crack 90s");
    delay(2000);
  }
  else if (sensorValues[0] > 3000 && sensorValues[1] > 3000 && sensorValues[2] > 3000 && sensorValues[3] > 3500 && sensorValues[4] < 3500 && sensorValues[5] < 3000 && sensorValues[6] < 3500 && sensorValues[7] < 3500) {
    izq(100);
    Serial.println ("crack 90s");
    delay(2000);
  }
}
