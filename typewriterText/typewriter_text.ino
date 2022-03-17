int row = 0;
int column = 0;

char *textBlock[]={
"And we wondered why so much of the Gulf was familiar to us, why this    ",
"town had a home feeling.  We had never seen a town which even looked    ",
"like La Paz, and yet coming to it was like returning rather than        ",
"visiting.  Some quality there is in the whole Gulf that trips a trigger ",
"of recognition so that in fantastic and exotic scenery one finds        ",
"oneself nodding and saying inwardly, Yes, I know.  And on the shore     ",
"the wild doves mourn in the evening and then there comes a pang, some   ",
"kind of emotional jar, and a longing.  And if one followed his          ",
"whispering impulse he would walk away slowly into the thorny brush      ",
"following the call of the doves. Trying to remember the Gulf is like    ",
"trying to re-create a dream.  This is by no means a sentimental thing,  ",
"it has little to do with beauty or even conscious liking.  But the Gulf ",
"does draw one, and we have talked to rich men who own boats, who can go ",
"where they will.  Regularly they find themselves sucked into the Gulf.  ",
"And since we have returned, there is always in the backs of our minds   ",
"the positive drive to go back again.  If it were lush and rich, one     ",
"could understand the pull, but it is fierce and hostile and sullen. The ",
"stone mountains pile up to the sky and there is little fresh water. But ",
"we know we must go back if we live, and we don't know why.              "
  };
char *printedLine;
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);


}

void loop() {

  printedLine = textBlock[row];
    if (column< 72 && row <19){
       Serial.print(printedLine[column]);
       column++;
       delay(100);
    }
    else if(column ==72 && row <19){
      Serial.println();
      row++;
      column=0;
    }
    else{
      row = 0;
      column = 0;
      delay(500);
    }


}
