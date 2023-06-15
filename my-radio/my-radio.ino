//Libraries:
#include <TEA5767.h>
#include <Wire.h>
#include <radio.h>

//Constants:
TEA5767 Radio;

void setup() {
  // init
  Serial.begin(9600);
  Radio.init();
  Radio.debugEnable();
  Radio.setFrequency(10330); 
  Radio.setVolume(1);

}

void loop() {
  // put your main code here, to run repeatedly:

}
