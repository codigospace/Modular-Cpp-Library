void setup() {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
}

void loop() {
  Serial.println('1');
  delay(2000);
  Serial.println('0');
  delay(2000);
  digitalWrite(2,LOW);
  delay(500);
  digitalWrite(2,HIGH);
  delay(3500);
}
