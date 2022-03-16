char *textBlock[]={"This is line 1","This is line 2","This is line 3",
  "This is line 4","This is line 5"};
  String printedLine;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);


}

void loop() {

 
    for (int i = 0; i < 5; i++){
      printedLine = textBlock[i];
       Serial.println(printedLine);
       delay(2000);
}

}
