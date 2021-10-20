/****************************************************************************
Agenda      :   Ringing the on-board Buzzer
Hardware    :   madBlocks IoT Suite
Programmer  :   Maddy
Date        :   20th Oct 2021
*****************************************************************************/

int buzzer=4;

#define BUZZER_ON 1
#define BUZZER_OFF 0

void setup() {
 pinMode(buzzer,OUTPUT);
}

void loop() {
 digitalWrite(buzzer,BUZZER_ON);
}
