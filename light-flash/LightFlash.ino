int morsePin = 10; //defining morse pin 10
int startPin = 11; //defining start pin

void setup() {
pinMode(morsePin, OUTPUT); //defining pin 10 with LED connected as output
pinMode(startPin, OUTPUT); //defining startPin 
}

void loop() {
  digitalWrite(startPin, HIGH); //starting LED on
  for (int i = 0; i < 3; ++i) {
    digitalWrite(morsePin, HIGH); //set LED on
    delay(300); //wait 1 second
    digitalWrite(startPin, LOW); //turning off
    digitalWrite(morsePin, LOW); //set LED off
    delay(300); //wait for a second
  }
  delay(900);
  for (int i = 0; i < 3; ++i) {
    digitalWrite(morsePin, HIGH); //set LED on
    delay(900); //wait 1 second
    digitalWrite(morsePin, LOW); //set LED off
    delay(300); //wait for a second
  }
  delay(900);
    for (int i = 0; i < 3; ++i) {
    digitalWrite(morsePin, HIGH); //set LED on
    delay(300); //wait 1 second
    digitalWrite(morsePin, LOW); //set LED off
    delay(300); //wait for a second
  }
  delay(2100);
}
