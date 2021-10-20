/****************************************************************************
Agenda      :   DHT11 Demo
Hardware    :   madBlocks IoT Suite
Programmer  :   Maddy
Date        :   20th Oct 2021
*****************************************************************************/

#include <LiquidCrystal.h>
#include "DHT.h"

DHT dht(2,DHT11);

int LCD_RS=23;
int LCD_EN=15;
int LCD_D4=25;
int LCD_D5=26;
int LCD_D6=27;
int LCD_D7=14;

LiquidCrystal lcd(LCD_RS,LCD_EN,LCD_D4,LCD_D5,LCD_D6,LCD_D7);

void setup() {
  dht.begin();
  lcd.begin(16,2);
  lcd.print("*** WELCOME TO");
  lcd.setCursor(0,1);
  lcd.print("   DHT Demo ***");
  delay(1000);
}

void loop() {
  float hum=dht.readHumidity();
  float temp=dht.readTemperature();

  if(isnan(hum) || isnan(temp)) {
    return;
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hum: ");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.setCursor(8,0);
  lcd.print(hum);
  lcd.setCursor(8,1);
  lcd.print(temp);
  delay(2000);
}
