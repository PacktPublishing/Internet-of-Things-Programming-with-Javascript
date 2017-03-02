#include "DHT.h"

#define DHTPIN 7 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  
  float sensor = analogRead(0);
  float light = sensor / 1024 * 100;
  
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println("%");
  
  Serial.print("Light: ");
  Serial.print(light);
  Serial.println("%");
  delay(700);
  }

