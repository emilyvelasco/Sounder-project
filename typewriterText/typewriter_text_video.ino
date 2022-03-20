#include <ESP_8_BIT_GFX.h>

// Create an instance of the graphics library
ESP_8_BIT_GFX videoOut(true /* = NTSC */, 8 /* = RGB332 color */);

int row = 0;
int column = 0;

String textBlock[]={
"So I didn\'t go. That Sunday I     \r\n",
"took some paper and sat down to    \r\n",
"write about how I had seen the     \r\n",
"President. His open car, trailing  \r\n",
"flowing streamers, had entered the \r\n",
"football stadium. One car, full of \r\n",
"secret service agents, went ahead  \r\n",
"and two cars followed close behind.\r\n",
"The agents were brave men with guns\r\n",
"to protect our President. The crowd\r\n",
"rose as the President\'s car       \r\n",
"entered the arena. There had never \r\n",
"been anything like it before. It   \r\n",
"was the President. It was him. He  \r\n",
"waved. We cheered. A band played.  \r\n",
"Seagulls circled overhead as if    \r\n",
"they too knew it was the President.\r\n",
"And there were skywriting airplanes\r\n",
"too. They wrote words in the sky   \r\n",
"like \"Prosperity is just around   \r\n",
"the corner.\" The President stood  \r\n",
"up in his car, and just as he did  \r\n",
"the clouds parted and the light    \r\n",
"from the sun fell across his face. \r\n",
"It was almost as if God knew too.  \r\n"
  };
String printedLine;
String storageLine;

void typewriter(){
  
   storageLine = textBlock[row];
    if (column< 40 && row <25){
      printedLine.concat(storageLine[column]);
      videoOut.print(printedLine);
       column++;
       delay(10);
    }
    else if(column ==40 && row <24){
      row++;
      column=0;
      //printedLine = "";
    }
    else{
      row = 0;
      column = 0;
      delay(150);
      printedLine = "";
    }
}

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
videoOut.begin();
videoOut.setRotation(1);

}

void loop() {
  videoOut.waitForFrame();
  videoOut.fillScreen(0);
  // Clear screen
  
  videoOut.setCursor(20, 30);
  videoOut.setTextColor(0x3C);
  videoOut.setTextSize(1);
  typewriter();
 


}
