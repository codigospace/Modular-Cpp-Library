#include <Modular.h>
motorDc motor(4);
analogInput pot(7);
void setup() {
  motor.init();
  pot.init();
}

void loop() {
  motor.write(map(pot.read(),0,1023,0,255),1);
}
