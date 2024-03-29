#include <Modular.h>

servoAngle servo(6);

void setup() {
  servo.init();
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1){
    servo.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 1){
    servo.write(pos);
    delay(15);
  }
}