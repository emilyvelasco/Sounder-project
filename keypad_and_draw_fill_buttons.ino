#include "Keypad.h"
#define BUZZER_PIN 4 // ESP32 GIOP21 pin connected to Buzzer's pin
/*

Example for ESP_8_BIT color composite video generator library on ESP32.
Connect GPIO25 to signal line, usually the center of composite video plug.

GFX Hello World

This demonstrates using the ESP_8_BIT_GFX class, which inherits from the
Adafruit GFX base class to deliver an easy to use graphics API. Draws two
rectangles that cycle around the border of the screen. The amount of corners
cut off from these rectangle show the amount of overscan on a particular
screen. In the middle of two rectangles are a bit of text drawn using
Adafruit GFX print() API.

Copyright (c) Roger Cheng

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <ESP_8_BIT_GFX.h>

// A list of 8-bit color values that work well in a cycle.
uint8_t colorCycle[] = {
  0xFF, // White
  0xFE, // Lowering blue
  0xFD,
  0xFC, // No blue
  0xFD, // Raising blue
  0xFE,
  0xFF, // White
  0xF3, // Lowering green
  0xE7,
  0xE3, // No green
  0xE7, // Raising green
  0xF3,
  0xFF, // White
  0x9F, // Lowering red
  0x5F,
  0x1F, // No red
  0x5F, // Raising red
  0x9F,
  0xFF
};

// Create an instance of the graphics library
ESP_8_BIT_GFX videoOut(true /* = NTSC */, 8 /* = RGB332 color */);

char * words[12] = {
  "one", "two", "three", "four" , "five" , "six" , "seven" , "eight" , "nine" , "asterisk" , "zero" , "pound"};

 
const byte ROWS = 4; // number of rows
const byte COLS = 3; // number of columns
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'#','0','*'}
};

byte rowPins[ROWS] = {23, 22, 3, 21}; 
byte colPins[COLS] = {19, 18, 5};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
 
void setup()
{
  videoOut.begin();
  //flip screen around to orient correctly on CRT
  videoOut.setRotation(3);
  //Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
}
//create a beep of tone and duration set by the user
void buzzy(int beepLength, int pitch){
int starttime = millis();
int endtime = starttime;

//int endtime = starttime+beepLength;
while ((endtime - starttime) <=beepLength){
  digitalWrite(BUZZER_PIN, HIGH); delay(pitch);
  digitalWrite(BUZZER_PIN, LOW); delay(pitch);
  endtime = millis();
 }
     
}
//blacken the graphical element representing the pressed button by a duration set by the user
void fillButton(int buttonX, int buttonY, int buttonW, int buttonH, int buttonColor, int buttonTime){
  int starttime = millis();
  int endtime = starttime;
  while ((endtime - starttime) <=buttonTime){
  videoOut.setRotation(3);
  videoOut.waitForFrame();
  videoOut.fillRect(buttonX, buttonY, buttonW, buttonH, buttonColor);
  endtime = millis();
  //videoOut.fillScreen(0);
  }
}


//keypad is wired as a 4x3 but arranged as a 6x2. this arranges them to fix 6x2
void printKey( char key) {
  switch(key) {
   case '3': Serial.println("column 1, row 1"); buzzy(50, 1); fillButton(120, 20, 48, 28,  0x00, 100); break;
   case '6': Serial.println("column 1, row 2"); buzzy(50, 1); fillButton(120, 52, 48, 28,  0x00, 100); break;
   case '9': Serial.println("column 1, row 3"); buzzy(50, 1); fillButton(120, 84, 48, 28,  0x00, 100); break;
   case '*': Serial.println("column 1, row 4"); buzzy(50, 1); fillButton(120, 116, 48, 28,  0x00, 100); break;
   case '7': Serial.println("column 1, row 5"); buzzy(50, 1); fillButton(120, 148, 48, 28,  0x00, 100); break;
   case '1': Serial.println("column 1, row 6"); buzzy(50, 1); fillButton(120, 180, 48, 28,  0x00, 100); break;
   
  
   
   case '2': Serial.println("column 2, row 1"); buzzy(50, 1); fillButton(172, 20, 48, 28,  0x00, 50); break;
   case '5': Serial.println("column 2, row 2"); buzzy(50, 1); fillButton(172, 52, 48, 28,  0x00, 50); break;
   case '8': Serial.println("column 2, row 3"); buzzy(50, 1); fillButton(172, 84, 48, 28,  0x00, 50); break;
   case '0': Serial.println("column 2, row 4"); buzzy(50, 1); fillButton(172, 116, 48, 28,  0x0, 50); break;
   case '#': Serial.println("column 2, row 5"); buzzy(50, 1); fillButton(172, 148, 48, 28,  0x00, 50); break;
   case '4': Serial.println("column 2, row 6"); buzzy(50, 1); fillButton(172, 180, 48, 28,  0x00, 50); break;
   
   
   
   
       
    
  }
  
}

 
void loop()
{
    videoOut.setRotation(3);
    videoOut.waitForFrame();

  // Clear screen
  videoOut.fillScreen(0);
  // draw buttons on the screen
  // Left column
 
  videoOut.fillRect(120, 20, 48, 28,   0xFF);
  videoOut.fillRect(120, 52, 48, 28,   0xFF);
  videoOut.fillRect(120, 84, 48, 28,   0xFF);
  videoOut.fillRect(120, 116, 48, 28,   0xFF);
  videoOut.fillRect(120, 148, 48, 28,   0xFF);
  videoOut.fillRect(120, 180, 48, 28,   0xFF);
  
  //Right column
  videoOut.fillRect(172, 20, 48, 28,   0xFF);
  videoOut.fillRect(172, 52, 48, 28,   0xFF);
  videoOut.fillRect(172, 84, 48, 28,   0xFF);
  videoOut.fillRect(172, 116, 48, 28,   0xFF);
  videoOut.fillRect(172, 148, 48, 28,   0xFF);
  videoOut.fillRect(172, 180, 48, 28,   0xFF);
  
  char key = keypad.getKey(); 
  if (key != NO_KEY){
  
    printKey(key);
 
  }
}
