#include <IRremote.h>

const int IR_RECEIVE_PIN = 7;

void setup(){
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
 
}

void loop(){
  if (IrReceiver.decode()){
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        IrReceiver.resume();
  }
}