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
