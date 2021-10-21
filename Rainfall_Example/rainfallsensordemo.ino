/****************************************************************************
Agenda      :   Rainfall Sensor Demo
Hardware    :   madBlocks IoT Suite
Programmer  :   Maddy
Date        :   20th Oct 2021
*****************************************************************************/

#include <LiquidCrystal.h>

int rainfall=39;

int LCD_RS=23;
int LCD_EN=15;
int LCD_D4=25;
int LCD_D5=26;
int LCD_D6=27;
int LCD_D7=14;

LiquidCrystal lcd(LCD_RS,LCD_EN,LCD_D4,LCD_D5,LCD_D6,LCD_D7);

void setup() {
  
  lcd.begin(16,2);
  lcd.print("*** WELCOME TO");
  lcd.setCursor(0,1);
  lcd.print("     Demo ***");
  delay(1000);
}

void loop() {
  int r=map(analogRead(rainfall),0,4095,100,0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Rain: ");
  lcd.setCursor(8,0);
  lcd.print(r);
  delay(2000);
}
