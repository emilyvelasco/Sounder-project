#include "Keypad.h"
#define BUZZER_PIN 4 // ESP32 GIOP21 pin connected to Buzzer's pin


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
  Serial.begin(9600);
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


void printKey( char key) {
  switch(key) {
   case '0': Serial.println("column 2, row 4"); buzzy(150, 8);  break;
   case '1': Serial.println("column 1, row 6"); buzzy(150, 11);  break;
   case '2': Serial.println("column 2, row 1"); buzzy(150, 2);  break;
   case '3': Serial.println("column 1, row 1"); buzzy(150, 1);  break;
   case '4': Serial.println("column 2, row 6"); buzzy(150, 12);  break;
   case '5': Serial.println("column 2, row 2"); buzzy(150, 4);  break;
   case '6': Serial.println("column 1, row 2"); buzzy(150, 3);  break;
   case '7': Serial.println("column 1, row 5"); buzzy(150, 9);  break;
   case '8': Serial.println("column 2, row 3"); buzzy(150, 6);  break;
   case '9': Serial.println("column 1, row 3"); buzzy(150, 5);  break;    
   case '*': Serial.println("column 1, row 4"); buzzy(150, 7);  break;
   case '#': Serial.println("column 2, row 5"); buzzy(150, 10);  break;    
  }
  
}

 
void loop()
{

  char key = keypad.getKey(); 
  if (key != NO_KEY){
  
    printKey(key);
 
  }
}
