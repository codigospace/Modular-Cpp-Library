#include <Modular.h>
// Variables para comunicacion serial
int dato=0;
bool state=0;

digitalOutput led(9);
long anteriorLed;

digitalInput  pulsador(8);
char estadoPulsador = '0';

analogInput pot(7);
int datoAdc;

servoAngle servo(6);
byte angle=0;
bool sentido=1;
long anteriorServo;

distanceSensor  distancia(5);
int datoUs;

motorDc motor(4);
bool sentidoDc=1;

long anteriorTiempo;

void setup() {
  Serial.begin(115200);
  led.init();
  anteriorLed = millis();
  pulsador.init();
  pot.init();
  servo.init();
  distancia.init();
  motor.init();
}

void loop() {
  if (Serial.available()){
    switch (Serial.read()){
      case '1':
        state=1;
      break;
      case '0':
        state=0;
      break;
    }    
  }
  
  if(millis()-anteriorLed>1000){
    anteriorLed = millis();
    led.write(!led.read());      
  }
  if (pulsador.change(HIGH)){
    estadoPulsador = '1';
    sentidoDc = !sentidoDc;
  }
  if(millis()-anteriorServo>20){
    anteriorServo=millis();
    if(sentido){
      if (angle<180){
        angle++;
      }
      else{
        sentido=0;
      }
    }
    else{
      if (angle>0){
        angle--;
      }
      else{
        sentido=1;
      }
    }
    servo.write(angle);
  }
  if(millis()-anteriorTiempo>500){
    anteriorTiempo = millis();
    if (state){
      dato++;
    }
    datoAdc = pot.read();
    datoUs = distancia.read();
    motor.write(map(pot.read(),0,1023,0,255),sentidoDc); 
    Serial.print("Serial:");
    Serial.print(dato);
    Serial.print(" Analog:");
    Serial.print(datoAdc);
    Serial.print(" Pulsador:");
    Serial.print(estadoPulsador);
    Serial.print(" Distancia:");
    Serial.println(datoUs);
    estadoPulsador = '0';
  }
}
