#include <Modular.h>

digitalOutput led(9);

void setup() {
  led.init();
}

void loop() {
  led.write(!led.read());
  delay(1000);
}