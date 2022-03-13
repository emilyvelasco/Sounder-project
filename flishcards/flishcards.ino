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
#include "fishlayers.h"
#include "pufferlayers.h"
#include "anglerlayers.h"
#include "molalayers.h"
int i = 0;

// Create an instance of the graphics library
ESP_8_BIT_GFX videoOut(true /* = NTSC */, 8 /* = RGB332 color */);

void setup() {
  
  // Initial setup of graphics library
  videoOut.begin();
    videoOut.waitForFrame();

  // Clear screen
  videoOut.fillScreen(0);
}

void drawGrouper(){
  videoOut.waitForFrame();
  videoOut.fillScreen(0);
  videoOut.drawBitmap(0, 0, epd_bitmap_grouper_gray1, 255, 239, 0x88);
  videoOut.drawBitmap(0, 0, epd_bitmap_grouper_gray2, 255, 239, 0xEC);
  videoOut.drawBitmap(0, 0, epd_bitmap_grouper_gray3, 255, 239, 0xF5);
  videoOut.fillRect(40, 170, 174, 30, 0x00);
  videoOut.drawRect(40, 170, 174, 30, 0xF5);
  videoOut.setCursor(86, 177);
  videoOut.setTextColor(0xEC);
  videoOut.setTextSize(2);
  videoOut.print("GROUPER");

}

void drawPuffer(){
  videoOut.waitForFrame();
  videoOut.fillScreen(0);
  videoOut.drawBitmap(0, 0, epd_bitmap_puffer_gray1, 255, 239, 0x88);
  videoOut.drawBitmap(0, 0, epd_bitmap_puffer_gray2, 255, 239, 0xEC);
  videoOut.drawBitmap(0, 0, epd_bitmap_puffer_gray3, 255, 239, 0xF5);
  videoOut.fillRect(40, 170, 174, 30, 0x00);
  videoOut.drawRect(40, 170, 174, 30, 0xF5);
  videoOut.setCursor(90, 177);
  videoOut.setTextColor(0xEC);
  videoOut.setTextSize(2);
  videoOut.print("PUFFER");
}


void drawAngler(){
  videoOut.waitForFrame();
  videoOut.fillScreen(0);
  videoOut.drawBitmap(0, 0, epd_bitmap_anglerfish_gray1, 255, 239, 0x88);
  videoOut.drawBitmap(0, 0, epd_bitmap_anglerfish_gray2, 255, 239, 0xEC);
  videoOut.drawBitmap(0, 0, epd_bitmap_anglerfish_gray3, 255, 239, 0xF5);
  videoOut.fillRect(40, 170, 174, 30, 0x00);
  videoOut.drawRect(40, 170, 174, 30, 0xF5);
  videoOut.setCursor(66, 177);
  videoOut.setTextColor(0xEC);
  videoOut.setTextSize(2);
  videoOut.print("ANGLERFISH");
}

void drawMola(){
  videoOut.waitForFrame();
  videoOut.fillScreen(0);
  videoOut.drawBitmap(0, 0, epd_bitmap_Mola_gray1, 255, 239, 0x88);
  videoOut.drawBitmap(0, 0, epd_bitmap_Mola_gray2, 255, 239, 0xEC);
  videoOut.drawBitmap(0, 0, epd_bitmap_Mola_gray3, 255, 239, 0xF5);
  videoOut.fillRect(40, 170, 174, 30, 0x00);
  videoOut.drawRect(40, 170, 174, 30, 0xF5);
  videoOut.setCursor(76, 177);
  videoOut.setTextColor(0xEC);
  videoOut.setTextSize(2);
  videoOut.print("MOLA MOLA");
}


void loop() {
    drawGrouper();  
    delay(2000);
    drawPuffer();
    delay(2000);
    drawAngler();  
    delay(2000);
    drawMola();
    delay(2000);
   }
