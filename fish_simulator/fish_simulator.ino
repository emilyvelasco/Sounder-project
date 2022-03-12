#include <ESP_8_BIT_GFX.h>
#include "Fish.h"
#include "Fish2.h"
#include "Fish3.h"
#include "seaweeds.h"
#include "bubbles.h"

// Create an instance of the graphics library
ESP_8_BIT_GFX videoOut(true /* = NTSC */, 8 /* = RGB332 color */);

bubble oneBubble(random(0,255), 239, 1, 0xE8, 6);
bubble twoBubble(random(0,255), 239, 1.3, 0xE8, 8);
bubble threeBubble(random(0,255), 239, .7, 0xE8, 5);

circle_fish mudfish(100,120,.7,0xE8, 0.05, 3);

circle_fish2 shark(100,120,.5,0xE8, 0.03, 3.5);

circle_fish3 roundfish(100,120,.3,0xE8, 0.03, 2);

//bubbles Bubble(120, 120, 1, 0xE8);

void setup() {
  // Initial setup of graphics library
  videoOut.begin();

}

void loop() {
  // Wait for the next frame to start working on frame buffer
  videoOut.waitForFrame();

  // Clear screen
  videoOut.fillScreen(0);

  oneBubble.draw(videoOut);
  twoBubble.draw(videoOut);
  threeBubble.draw(videoOut);


  mudfish.draw(videoOut);

  shark.draw(videoOut);

  roundfish.draw(videoOut);


  videoOut.drawBitmap(10, 15,  epd_bitmap_left_seaweed, 31, 221, 0xE8);
  videoOut.drawBitmap(200, 13,  epd_bitmap_right_seaweed, 32, 221, 0xE8);


}
