#include "Arduino.h"
#include "LoRa_E32.h"
#include "DHT.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(23,15,25,26,27,14);
DHT dht(2,DHT11);
LoRa_E32 e32ttl100(&Serial2, 22, 21, 33);//M0,M1,AUX
struct myData{
  int temp;
  int hum;
  int sm;
  int rf;
};
myData data;

void setup()
{
  lcd.begin(16,2);
  lcd.print("**WElCOME TO**");
  lcd.setCursor(0,1);
  lcd.print("madBlocks Academy");
  delay(1000);
  pinMode(19,OUTPUT);
  Serial.begin(115200);
  delay(500);
  lcd.clear();
  dht.begin();
  e32ttl100.begin();
}

void loop() 
{
	send_data();
}

void send_data()
{
    lcd.clear();
    lcd.print("Sending Data...");
    digitalWrite(19,HIGH);
    delay(400);
    float hum=dht.readHumidity();
    float temp_c=dht.readTemperature();
    if(isnan(hum) || isnan(temp_c))
    {
      lcd.clear();
      lcd.print("DHT Sensor");
      lcd.setCursor(0,1);
      lcd.print("NOT Connected");
      delay(500);
      Serial.println("No Data Received");
      return;
    }
    data.temp=dht.readTemperature();
    data.hum=dht.readHumidity();
    data.sm=map(analogRead(34),0,4095,100,0);
    data.rf=map(analogRead(39),0,4095,100,0);
    lcd.clear();
    lcd.print("H:");
    lcd.print(data.hum);
    lcd.setCursor(8,0);
    lcd.print("T:");
    lcd.print(data.temp);
    lcd.setCursor(0,1);
    lcd.print("SM:");
    lcd.print(data.sm);
    lcd.setCursor(8,1);
    lcd.print("RF:");
    lcd.print(data.rf);
    ResponseStatus rs = e32ttl100.sendMessage(&data,sizeof(data));
    Serial.println(rs.getResponseDescription());
    digitalWrite(19,LOW);
    delay(1000);
    lcd.clear();
    lcd.print("Data Sent...........");
    delay(1000);
}
