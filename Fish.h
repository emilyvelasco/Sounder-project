#include <ESP_8_BIT_GFX.h>
float incrementer;
float fishWiggle;
float wiggleAmount;
// Fish
class circle_fish
{
  public:
    circle_fish(float start_x, float start_y, float start_deltaX, int start_color, float wiggleValue, float wiggleHeight)
    {
      x = start_x;
      y = start_y;
      deltaX = start_deltaX;
      color = start_color;
      fishWiggle = wiggleValue;
      wiggleAmount = wiggleHeight;
    }
   
    void draw(ESP_8_BIT_GFX gfx)
    {
      gfx.drawCircle(x, y, 10, color);
     if(x<255){ 
      x += deltaX;
      y+=(sin(incrementer)/wiggleAmount);
      incrementer+=fishWiggle;
     }
       else{
    x=0;
    y=random(20,219);
    incrementer=0;
  }
    }

  private:
    float x, y, deltaX;
    int color;
};
