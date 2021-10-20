/****************************************************************************
Agenda      :   Switching the LED, Buzzer based on SW1, SW2, SW3
Hardware    :   madBlocks IoT Suite
Programmer  :   Maddy
Date        :   20th Oct 2021
*****************************************************************************/

int buzzer=4;
int switch1=18;
int switch2=5;
int switch3=36;

int led1=13;
int led2=12;
int led3=19;
int led4=32;

#define ON 1
#define OFF 0

int outputs[]={led1,led2,led3,led4,buzzer};
int inputs[]={switch1,switch2,switch3};

void setup() {
 for(int i=0;i<5;i++) {
  pinMode(outputs[i],OUTPUT);
 }
 for(int i=0;i<3;i++) {
  pinMode(inputs[i],INPUT_PULLUP);
 }
}

void loop() {

  if(digitalRead(inputs[0])==0) {
    for(int i=0;i<4;i++) {
      digitalWrite(outputs[i],ON);
    }
  } else if(digitalRead(inputs[1])==0){
     digitalWrite(outputs[4],ON);
  } else if(digitalRead(inputs[2])==0) {
    for(int i=0;i<5;i++) {
      digitalWrite(outputs[i],OFF);
    }
  }
}
