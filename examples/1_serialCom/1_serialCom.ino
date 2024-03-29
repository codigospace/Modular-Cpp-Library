#include <Modular.h>

int dato=0;
bool state=0;
long lastTime;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()){
    switch (Serial.read()){
      case '1':
        Serial.println("Iniciando ...");
        state=1;
        lastTime=millis();
      break;
      case '0':
        Serial.println("Detenido");
        state=0;
        lastTime=millis();
      break;
      default:
        Serial.println("No valido, envia 1 para iniciar y 0 para detener");
      break;
    }    
  }
  if (state){
    if (millis()-lastTime>500){
      lastTime=millis();
      Serial.println(dato++);
    }
  }
}