#include "Arduino.h"
#include "LoRa_E32.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(23,15,25,26,27,14);
LoRa_E32 e32ttl100(&Serial2, 22, 21, 33);

struct myData{
  int temp;
  int hum;
  int sm;
  int rf;
};

void setup()
{
  lcd.begin(16,2);
  lcd.print("**WElCOME TO**");
  lcd.setCursor(0,1);
  lcd.print("madBlocks Academy");
  delay(1000);
  Serial.begin(115200);
  delay(500);
  e32ttl100.begin();
}

void loop() 
{
	if (e32ttl100.available()>1)
  {
	  ResponseStructContainer rc = e32ttl100.receiveMessage(sizeof(myData));
	  if (rc.status.code!=1)
	  {
		  rc.status.getResponseDescription();
	  }
	  else
	  {
		  // Print the data received
      lcd.clear();
      lcd.print("Data Received");
      delay(1000);
      struct myData mydata=*(myData*)rc.data;
      lcd.clear();
      lcd.print("Hum:");
      lcd.print(mydata.hum);
      lcd.setCursor(8,0);
      lcd.print("Temp:");
      lcd.print(mydata.temp);
      lcd.setCursor(0,1);
      lcd.print("Soil:");
      lcd.print(mydata.sm);
      lcd.setCursor(8,1);
      lcd.print("Rain:");
      lcd.print(mydata.rf);
		  Serial.print(mydata.temp);
      Serial.print("\t");
      Serial.print(mydata.hum);
      Serial.print("\t");
      Serial.print(mydata.sm);
      Serial.print("\t");
      Serial.println(mydata.rf);
      delay(2000);
	  }
  }
}
