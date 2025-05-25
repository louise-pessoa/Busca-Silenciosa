void setup() {
 pinMode(3, OUTPUT);

}

void loop() {
analogWrite(3, 120);
delay(1000);
analogWrite(3,10);
delay(1000);

}
