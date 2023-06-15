int DI = 12;
int RW = 11;
int DB[] = {3, 4, 5, 6, 7, 8, 9, 10};// use array to select pin for bus
int Enable = 2;
void LcdCommandWrite(int value) { // define all pins
  int i = 0;
  for (i=DB[0]; i <= DI; i++) { // assign value for bus 
   digitalWrite(i,value & 01);// for 1602 LCD, it uses D7-D0( not D0-D7) for signal identification; here, it’s used for signal inversion. 
   value >>= 1;
  }
  digitalWrite(Enable,LOW);
  delayMicroseconds(1);
  digitalWrite(Enable,HIGH);
  delayMicroseconds(1);  // wait for 1ms
  digitalWrite(Enable,LOW);
  delayMicroseconds(1);  // wait for 1ms
}

void LcdDataWrite(int value) { // initialize all pins
  int i = 0;
  digitalWrite(DI, HIGH);
  digitalWrite(RW, LOW);
  for (i=DB[0]; i <= DB[7]; i++) {
     digitalWrite(i,value & 01);
     value >>= 1;
  }
  digitalWrite(Enable,LOW);
  delayMicroseconds(1);
  digitalWrite(Enable,HIGH);
  delayMicroseconds(1);
  digitalWrite(Enable,LOW);
  delayMicroseconds(1);  // wait for 1ms
}

void setup (void) {
  int i = 0;
  for (i=Enable; i <= DI; i++) {
   pinMode(i,OUTPUT);
  }
  delay(100); // initialize LCD after a brief pause for LCD control
  LcdCommandWrite(0x38);  // select as 8-bit interface, 2-line display, 5x7 character size 
  delay(64);                      
  LcdCommandWrite(0x38);  // select as 8-bit interface, 2-line display, 5x7 character size 
  delay(50);                      
  LcdCommandWrite(0x38);  // select as 8-bit interface, 2-line display, 5x7 character size             
  delay(20);                      
  LcdCommandWrite(0x06);  // set input mode
                         // auto-increment, no display of shifting
  delay(20);                      
  LcdCommandWrite(0x0E);  // display setup
                         // turn on the monitor, cursor on, no flickering
  delay(20);                      
  LcdCommandWrite(0x01);  // clear the screen, cursor position returns to 0
  delay(100);                      
  LcdCommandWrite(0x80);  //  display setup
                         //  turn on the monitor, cursor on, no flickering

  delay(20);                    
}

void loop (void) {
  LcdCommandWrite(0x01); // clear the screen, cursor position returns to 0  
  delay(10); 
 // LcdCommandWrite(0x80+3); 
  delay(10); 
  // write in welcome message 
  //char m[] = "hi my name is bob and i approve this message";
  String text = "subscribe to my OnlyFans for elite pictures of my fat fucking cock "; //make sure to add a space to the end of the string
  int i = 0;
  while (i < text.length()) {
    LcdDataWrite(text[i]);
    if (text[i]==' ') {
      int currentFrame = i/15;
      int nextWordFrame = text.indexOf(' ', i+1)/15;
      if (currentFrame != nextWordFrame) {
        delay(1500);
        LcdCommandWrite(0x01);  // clear the screen, cursor returns to 0  
        delay(10);
      }
    }
    i++;
  }
  
  delay(5000);
}