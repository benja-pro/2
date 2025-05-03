#include "variable.h"

void setup() {
  motorSetup();
}

void loop() {
  motor(50, 50);
  delay(10000);
  atras(50, 50);
  delay(10000);
  parar(50, 50);
  delay(10000);
  iz(50, 50);
  delay(10000);
  de(50, 50);
  delay(10000);
}
