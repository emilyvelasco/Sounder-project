int row = 0;
int column = 0;

char *textBlock[]={"This is line 1","This is line 2","This is line 3",
  "This is line 4","This is line 5"};
  char *printedLine;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);


}

void loop() {

  printedLine = textBlock[row];
    if (column< 14 && row <5){
       Serial.print(printedLine[column]);
       column++;
       delay(100);
    }
    else if(column ==14 && row <5){
      Serial.println();
      row++;
      column=0;
    }
    else{
      row = 0;
      column = 0;
      delay(1000);
    }


}
