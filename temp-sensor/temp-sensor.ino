#include "DHT.h"
#include <EEPROM.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int cycles = 0;
int tempAddress = 0;
int humiAddress = 1;

void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize the sensor
}

void loop() {
  // wait a few seconds between measurements.
  delay(2000);

  // read humidity
  float humi  = dht.readHumidity();
  // read temperature as Celsius
  float tempC = dht.readTemperature();
  // read temperature as Fahrenheit
  float tempF = dht.readTemperature(true);

  // // check if any reads failed
  // if (isnan(humi) || isnan(tempC) || isnan(tempF)) {
  //   Serial.println("Failed to read from DHT sensor!");
  // } else {
  //   Serial.print("Humidity: ");
  //   Serial.print(humi);
  //   Serial.print("%");

  //   Serial.print("  |  "); 

  //   Serial.print("Temperature: ");
  //   Serial.print(tempC);
  //   Serial.print("°C ~ ");
  //   Serial.print(tempF);
  //   Serial.println("°F");
  //}
  if (cycles%1000 == 0) {
      EEPROM.write(tempAddress, tempF);
      EEPROM.write(humiAddress, humi);
      Serial.print(EEPROM.read(tempAddress));
      Serial.print(EEPROM.read(humiAddress));
      tempAddress++;
      humiAddress++;
    }
  cycles++;
  //Serial.println(cycles);
}

// #include <EEPROM.h>
// int tempAddress = 0;
// int humiAddress = 1;
// int address = 0;
// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   // Serial.println(EEPROM.read(tempAddress));
//   // Serial.println(EEPROM.read(humiAddress));
//   // tempAddress++;
//   // humiAddress++;
//   Serial.println(EEPROM.read(address));
//   address++;
//   delay(2000);
// }

