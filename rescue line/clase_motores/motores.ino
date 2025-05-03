void motorSetup() {
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
  ledcSetup(1, frecuencia, resolucion);
  ledcAttachPin(pwmA, 1);
  ledcSetup(2, frecuencia, resolucion);
  ledcAttachPin(pwmB, 2);
}
void motor(int veliz, int velde) {
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, HIGH);
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, LOW);
  ledcWrite(1, veliz);
  ledcWrite(2, velde);
}
void atras(int veliz, int velde) {
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, HIGH);
  ledcWrite(1, veliz);
  ledcWrite(2, velde);
}
void parar(int veliz, int velde) {
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, LOW);
  ledcWrite(1, veliz);
  ledcWrite(2, velde);
}
void de(int veliz, int velde) {
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, LOW);
  ledcWrite(1, veliz);
  ledcWrite(2, velde);
}
void iz(int veliz, int velde) {
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, HIGH);
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, HIGH);
  ledcWrite(1, veliz);
  ledcWrite(2, velde);
}
