#include <Modular.h>

digitalOutput led(9);
digitalInput  pulsador(8);

void setup() {
  led.init();
  pulsador.init();
  Serial.begin(115200);
}

void loop() {
  led.write(pulsador.read());
  Serial.println(pulsador.change(LOW));
  delay(100);
}