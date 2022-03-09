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
#include "buttons.h"
#include "buzzy.h"

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

//blacken the graphical element representing the pressed button by a duration set by the user
void invertButton(int buttonX, int buttonY, const uint8_t bitmapName[], int buttonW, int buttonH, int buttonColor, int buttonBG, int buttonTime){
  int starttime = millis();
  int endtime = starttime;
  while ((endtime - starttime) <=buttonTime){
  videoOut.setRotation(3);
  videoOut.waitForFrame();
  videoOut.drawBitmap(buttonX, buttonY, bitmapName, buttonW, buttonH, buttonColor, buttonBG);
  endtime = millis();
  //videoOut.fillScreen(0);
  }
}


//keypad is wired as a 4x3 but arranged as a 6x2. this arranges them to fix 6x2
void printKey( char key) {
  switch(key) {
   case '3': /*Serial.println("column 1, row 1");*/ buzzy(50, 1); 
    invertButton(70, 10,  epd_bitmap_up_up_down, 44, 33, 0x00, 0xE0, 50); break;
   case '6': /*Serial.println("column 1, row 2");*/ buzzy(50, 1); 
    invertButton(70, 47,  epd_bitmap_up_short_long, 44, 33, 0x00, 0xE0, 50); break;
   case '9': /*Serial.println("column 1, row 3");*/ buzzy(50, 1); 
    invertButton(70, 84,  epd_bitmap_up_arrow, 44, 33, 0x00, 0xE0, 50); break;
   case '*': /*Serial.println("column 1, row 4");*/ buzzy(50, 1); 
    invertButton(70, 121,  epd_bitmap_NL, 44, 33, 0x00, 0xE0, 50); break;
   case '7': /*Serial.println("column 1, row 5");*/ buzzy(50, 1); 
    invertButton(70, 158,  epd_bitmap_up_upper_right, 44, 33, 0x00, 0xE0, 50); break;
   case '1': /*Serial.println("column 1, row 6");*/ buzzy(50, 1); 
    invertButton(70, 195,  epd_bitmap_up_lower_left, 44, 33, 0x00, 0xE0, 50); break;
   
  
   
   case '2': /*Serial.println("column 2, row 1");*/ buzzy(50, 1);
     invertButton(118, 10,  epd_bitmap_down_up_down, 44, 33, 0x00, 0xE0, 50); break;
   case '5': /*Serial.println("column 2, row 2");*/ buzzy(50, 1);
    invertButton(118, 47,  epd_bitmap_down_short_long, 44, 33, 0x00, 0xE0, 50); break;
   case '8': /*Serial.println("column 2, row 3");*/ buzzy(50, 1);
    invertButton(118, 84,  epd_bitmap_down_arrow, 44, 33, 0x00, 0xE0, 50); break;
   case '0': /*Serial.println("column 2, row 4");*/ buzzy(50, 1);
    invertButton(118, 121,  epd_bitmap_speaker, 44, 33, 0x00, 0xE0, 50); break;
   case '#': /*Serial.println("column 2, row 5");*/ buzzy(50, 1);
    invertButton(118, 158,  epd_bitmap_down_upper_right, 44, 33, 0x00, 0xE0, 50); break;
   case '4': /*Serial.println("column 2, row 6");*/ buzzy(50, 1);
    invertButton(118, 195,  epd_bitmap_down_lower_left, 44, 33, 0x00, 0xE0, 50); break;
   
   
   
   
       
    
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
 
  videoOut.drawBitmap(70, 10,  epd_bitmap_up_up_down, 44, 33, 0xE0);
  videoOut.drawBitmap(70, 47,  epd_bitmap_up_short_long, 44, 33, 0xE0);
  videoOut.drawBitmap(70, 84,  epd_bitmap_up_arrow, 44, 33, 0xE0);
  videoOut.drawBitmap(70, 121,  epd_bitmap_NL, 44, 33, 0xE0);
  videoOut.drawBitmap(70, 158,  epd_bitmap_up_upper_right, 44, 33, 0xE0);
  videoOut.drawBitmap(70, 195,  epd_bitmap_up_lower_left, 44, 33, 0xE0);
  
  //Right column
  videoOut.drawBitmap(118, 10,  epd_bitmap_down_up_down, 44, 33, 0xE0);
  videoOut.drawBitmap(118, 47,  epd_bitmap_down_short_long, 44, 33, 0xE0);
  videoOut.drawBitmap(118, 84,  epd_bitmap_down_arrow, 44, 33, 0xE0);
  videoOut.drawBitmap(118, 121,  epd_bitmap_speaker, 44, 33, 0xE0);
  videoOut.drawBitmap(118, 158,  epd_bitmap_down_upper_right, 44, 33, 0xE0);
  videoOut.drawBitmap(118, 195,  epd_bitmap_down_lower_left, 44, 33, 0xE0);
  
  char key = keypad.getKey(); 
  if (key != NO_KEY){
  
    printKey(key);
 
  }
}
