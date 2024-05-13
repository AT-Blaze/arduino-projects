/// \file  TestTEA5767.ino
/// \brief An Arduino sketch to operate a TEA5767 chip based radio using the Radio library.
///
/// \author Matthias Hertel, http://www.mathertel.de
/// \copyright Copyright (c) 2014 by Matthias Hertel.\n
/// This work is licensed under a BSD style license.\n
/// See http://www.mathertel.de/License.aspx
///
/// \details
/// This sketch implements a "as simple as possible" radio without any possibility to modify the settings after initializing the chip.\n
/// The radio chip is initialized and setup to a fixed band and frequency. These settings can be changed by modifying the 
/// FIX_BAND and FIX_STATION definitions. 
///
/// Open the Serial console with 57600 baud to see the current radio information.
///
/// Wiring
/// ------ 
/// Arduino port | TEA5767 signal
/// ------------ | ---------------
///         3.3V | VCC
///          GND | GND
///           A5 | SCLK
///           A4 | SDIO
///           D2 | RST
///
/// More documentation is available at http://www.mathertel.de/Arduino
/// Source Code is available on https://github.com/mathertel/Radio
///
/// History:
/// --------
/// * 15.09.2014 created.
/// * 15.11.2015 wiring corrected.

#include <Arduino.h>
#include <Wire.h>
#include <radio.h>
#include <TEA5767.h>
#include <ezButton.h>

TEA5767 radio;    // Create an instance of Class for Si4703 Chip

#define FIX_BAND RADIO_BAND_FM
#define FIX_STATION 9010

int station = 9010;

ezButton button(7);

void setup() {
  // open the Serial port
  Serial.begin(9600);
  radio.init();
  radio.debugEnable();
  radio.setVolume(1); 
  radio.setBandFrequency(FIX_BAND, FIX_STATION);  
  radio.setMono(false);

  button.setDebounceTime(50);} 

void loop(){ 
  radio.setFrequency(station);
  button.loop();
  if(button.isPressed())
    Serial.println("button pressed");

  if(button.isReleased())
    Serial.println("released");
  delay(500);
}

