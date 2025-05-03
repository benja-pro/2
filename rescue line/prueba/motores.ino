void front(int vel) {
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, HIGH);
  ledcWrite(1, vel);
  ledcWrite(0, vel);
}

void der(int vel) {
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, LOW);
  ledcWrite(1, vel);
  ledcWrite(0, vel);
}

void izq(int vel) {
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, HIGH);
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, HIGH);
  ledcWrite(1, vel);
  ledcWrite(0, vel);
}
