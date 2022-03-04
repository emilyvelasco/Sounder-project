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
  //Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
}

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

void fillButton(int buttonX int buttonY int buttonW int buttonH int buttonColor int buttonTime){
  videoOut.fillRect(buttonX, buttonY, buttonW, buttonH, buttonColor);
  delay(buttonTime);
  videoOut.fillScreen(0);
}



void printKey( char key) {
  switch(key) {
   case '0': Serial.println("column 2, row 4"); buzzy(50, 1); videoOut.fillRect(132, 122, 48, 28, 0xFF); break;
   case '1': Serial.println("column 1, row 6"); buzzy(50, 1); videoOut.fillRect(78, 186, 48, 28, 0xFF); break;
   case '2': Serial.println("column 2, row 1"); buzzy(50, 1); videoOut.fillRect(132, 26, 48, 28, 0xFF); break;
   case '3': Serial.println("column 1, row 1"); buzzy(50, 1); videoOut.fillRect(78, 26, 48, 28, 0xFF); break;
   case '4': Serial.println("column 2, row 6"); buzzy(50, 1); videoOut.fillRect(132, 186, 48, 28, 0xFF); break;
   case '5': Serial.println("column 2, row 2"); buzzy(50, 1); videoOut.fillRect(132, 58, 48, 28, 0xFF); break;
   case '6': Serial.println("column 1, row 2"); buzzy(50, 1); videoOut.fillRect(78, 58, 48, 28, 0xFF); break;
   case '7': Serial.println("column 1, row 5"); buzzy(50, 1); videoOut.fillRect(78, 154, 48, 28, 0xFF); break;
   case '8': Serial.println("column 2, row 3"); buzzy(50, 1); videoOut.fillRect(132, 90, 48, 28, 0xFF); break;
   case '9': Serial.println("column 1, row 3"); buzzy(50, 1); videoOut.fillRect(78, 90, 48, 28, 0xFF); break;    
   case '*': Serial.println("column 1, row 4"); buzzy(50, 1); videoOut.fillRect(78, 122, 48, 28, 0xFF); break;
   case '#': Serial.println("column 2, row 5"); buzzy(50, 1); videoOut.fillRect(132, 186, 48, 28, 0xFF); break;    
  }
  
}

 
void loop()
{
    videoOut.waitForFrame();

  // Clear screen
  videoOut.fillScreen(0);

  // Left column
  videoOut.drawRect(78, 26, 48, 28, 0xFF);
  videoOut.drawRect(78, 58, 48, 28, 0xFF);
  videoOut.drawRect(78, 90, 48, 28, 0xFF);
  videoOut.drawRect(78, 122, 48, 28, 0xFF);
  videoOut.drawRect(78, 154, 48, 28, 0xFF);
  videoOut.drawRect(78, 186, 48, 28, 0xFF);
  
  //Right column
  videoOut.drawRect(132, 26, 48, 28, 0xFF);
  videoOut.drawRect(132, 58, 48, 28, 0xFF);
  videoOut.drawRect(132, 90, 48, 28, 0xFF);
  videoOut.drawRect(132, 122, 48, 28, 0xFF);
  videoOut.drawRect(132, 154, 48, 28, 0xFF);
  videoOut.drawRect(132, 186, 48, 28, 0xFF);
  videoOut.drawRect(132, 186, 48, 28, 0xFF);
  char key = keypad.getKey(); 
  if (key != NO_KEY){
  
    printKey(key);
 
  }
}
