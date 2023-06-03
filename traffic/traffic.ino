int redled = 2;
int yellowled = 3;
int blueled = 4;

void setup() {
pinMode(redled, OUTPUT);
pinMode(yellowled, OUTPUT);
pinMode(blueled, OUTPUT);
}

void loop() {
digitalWrite(blueled, HIGH);
delay(5000);
digitalWrite(blueled, LOW);

for(int i=0; i < 3; i ++) {
  delay(500);
  digitalWrite(yellowled, HIGH);
  delay(500);
  digitalWrite(yellowled, LOW);
}

delay(500);
digitalWrite(redled, HIGH);
delay(5000);
digitalWrite(redled, LOW);

}