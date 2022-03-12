#include <ESP_8_BIT_GFX.h>
#include "Fish.h"
#include "Fish2.h"

// Create an instance of the graphics library
ESP_8_BIT_GFX videoOut(true /* = NTSC */, 8 /* = RGB332 color */);


circle_fish red_fish(100,120,.7,0xE8, 0.05, .5);
circle_fish blue_fish(200,40,1,0xE8, .08, 2);
circle_fish2 one_fish(100,120,.5,0xE8, 0.03, .4);
circle_fish2 two_fish(200,40,.3,0xE8, .1, 1);

void setup() {
  // Initial setup of graphics library
  videoOut.begin();
}

void loop() {
  // Wait for the next frame to start working on frame buffer
  videoOut.waitForFrame();

  // Clear screen
  videoOut.fillScreen(0);

  red_fish.draw(videoOut);
  blue_fish.draw(videoOut);
  one_fish.draw(videoOut);
  two_fish.draw(videoOut);

}
