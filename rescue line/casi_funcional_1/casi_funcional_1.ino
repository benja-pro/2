#include <QTRSensors.h>
#include "Pines.h"

QTRSensors sigueLineas;

const int freq = 5000;
const int resolution = 8;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
int umbral = 3000;

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

}
//IZ = VERDE
