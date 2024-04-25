#include <Modular.h>
digitalOutput led(9);
void setup() {
  led.init();
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()){
    switch (Serial.read()){
      case '0':
        led.write(0);
        Serial.write('2');
      break;
      case '1':
        led.write(1);
        Serial.write('3');
      break;
    }
  }
}
