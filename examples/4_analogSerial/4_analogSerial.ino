#include <Modular.h>

analogInput pot(7);

void setup() {
  pot.init();
  Serial.begin(115200);
}

void loop() {
  Serial.println(pot.read());
  delay(100);
}