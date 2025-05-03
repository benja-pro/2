#include <QTRSensors.h>
#include "Pines.h"

QTRSensors sigueLineas;

const int freq = 5000;
const int resolution = 8;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

int umbral = 3500;

void setup() {
  Serial.begin(9600);
  sigueLineas.setTypeAnalog();

  sigueLineas.setSensorPins((const uint8_t[])
  {
    36, 39, 34, 35, 32, 33, 25, 26
  }, SensorCount);

  sigueLineas.setEmitterPin(27);

  inicializarMotores();
  while (digitalRead(BOTON) == 0) {
  }
}

void loop() {
  sigueLineas.read(sensorValues);
  linea();

  Serial.print(sensorValues[0]);
  Serial.print("  ");
  Serial.print(sensorValues[1]);
  Serial.print("  ");
  Serial.print(sensorValues[2]);
  Serial.print("  ");
  Serial.print(sensorValues[3]);
  Serial.print("  ");
  Serial.print(sensorValues[4]);
  Serial.print("  ");
  Serial.print(sensorValues[5]);
  Serial.print("  ");
  Serial.print(sensorValues[6]);
  Serial.print("  ");
  Serial.print(sensorValues[7]);
  Serial.println("  ");
}
//IZ = VERDE
void linea() {
  if (sensorValues[1] < umbral && sensorValues[2] < umbral && sensorValues[3] > umbral && sensorValues[4] > umbral && sensorValues[5] < umbral && sensorValues[6] < umbral) {
    Motor(80, 80);
    //rec
  }
  else if (sensorValues[1] < umbral && sensorValues[2] > umbral && sensorValues[3] > umbral && sensorValues[4] < umbral && sensorValues[5] < umbral && sensorValues[6] < umbral) {
    Motor (20, 50);
    //izd
  }
  else if (sensorValues[1] < umbral && sensorValues[2] < umbral && sensorValues[3] < umbral && sensorValues[4] > umbral && sensorValues[5] > umbral && sensorValues[6] < umbral) {
    Motor(50, 20);
    //ded
  }
  else if (sensorValues[1] > umbral && sensorValues[2] > umbral && sensorValues[3]  < umbral && sensorValues[4] < umbral && sensorValues[5] < umbral && sensorValues[6] < umbral) {
    Motor (0, 100);
    //izf
  }
  else if (sensorValues[1] < umbral && sensorValues[2] < umbral && sensorValues[3] < umbral && sensorValues[4] < umbral && sensorValues[5] > umbral && sensorValues[6] > umbral) {
    Motor(100, 0);
    //def
  }
}
