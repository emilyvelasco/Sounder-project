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

void setup() {
  // Initial setup of graphics library
  videoOut.begin();
}

void loop() {
  // Wait for the next frame to minimize chance of visible tearing
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
  videoOut.fillRect(132, 186, 48, 28, 0xFF);
  videoOut.drawRect(132, 186, 48, 28, 0xFF);

}
