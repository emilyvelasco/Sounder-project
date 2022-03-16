int row = 0;
int column = 0;

char *textBlock[]={"This is line 1","This is line 2","This is line 3",
  "This is line 4","This is line 5"};
  String printedLine;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);


}

void loop() {

 
    if (row< 5){
      printedLine = textBlock[row];
       Serial.println(printedLine);
       delay(2000);
       row++;
    }
    else{
      row = 0;
    }


}
