#include <ESP_8_BIT_GFX.h>
#include "fishpics.h"
float incrementer2;
float fishWiggle2;
float wiggleAmount2;
// Fish
class circle_fish2
{
  public:
    circle_fish2(float start_x, float start_y, float start_deltaX, int start_color, float wiggleValue, float wiggleHeight)
    {
      x = start_x;
      y = start_y;
      deltaX = start_deltaX;
      color = start_color;
      fishWiggle2 = wiggleValue;
      wiggleAmount2 = wiggleHeight;
    }
   
    void draw(ESP_8_BIT_GFX gfx)
    {
      gfx.drawBitmap(x, y, epd_bitmap_mudfish, 46, 28, color);
     if(x>0){ 
      x -= deltaX;
      y-=(sin(incrementer2)/wiggleAmount);
      incrementer2+=fishWiggle2;
     }
       else{
    x=255;
    y=random(20,219);
    incrementer2=0;
  }
    }

  private:
    float x, y, deltaX;
    int color;
};
