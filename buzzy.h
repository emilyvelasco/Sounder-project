//create a beep of tone and duration set by the user
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
