#include <Modular.h>

distanceSensor  distancia(5);

void setup() {
  distancia.init();
  Serial.begin(115200);
}

void loop() {
  Serial.println(distancia.read());
  delay(500);
}