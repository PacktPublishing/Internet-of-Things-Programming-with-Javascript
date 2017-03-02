#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 7 
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x3F,16,2);

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hello !!!");
  lcd.setCursor(1,1);
  lcd.print("Starting ...");

  dht.begin();

  delay(2000);
  lcd.clear();
}
void loop()
{
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  
  float sensor = analogRead(0);
  float light = sensor / 1024 * 100;
  
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temp,1);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(11,0);
  lcd.print("Lignt");
  
  lcd.setCursor(0,1);
  lcd.print("Hum:");
  lcd.print(hum);
  lcd.print("%");
  
  lcd.setCursor(11,1);
  lcd.print(light);
  lcd.print("%");
  
  delay(700);
  }

