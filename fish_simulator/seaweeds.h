#include <ESP_8_BIT_GFX.h>

// Bubble
class bubble
{
  public:
    bubble(float start_x, float start_y, float start_deltaY, int start_color, int diameter)
    {
      x = start_x;
      y = start_y;
      deltaY = start_deltaY;
      color = start_color;
      bubbleSize = diameter;
    }
   
    void draw(ESP_8_BIT_GFX gfx)
    {
      gfx.drawCircle(x, y, bubbleSize, color);
     if(y>0){ 
      y -= deltaY;
     }
       else{
    x=random(20,200);
    y=239;
  }
    }

  private:
    float x, y, deltaY;
    int color;
    int bubbleSize;
};
