#include "Pines.h"

const int freq = 5000;
const int resolution = 8;


void setup() {
  inicializarMotores();
  while (digitalRead(BOTON) == 0) {
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Motor(0,0);
}
