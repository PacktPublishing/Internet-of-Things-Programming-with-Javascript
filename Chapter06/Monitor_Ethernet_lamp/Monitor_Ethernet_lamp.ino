// Libraries
#include <SPI.h>
#include <Ethernet.h>
#include <aREST.h>
#include <avr/wdt.h>

// Libraries
#include "DHT.h"

// DHT sensor
#define DHTPIN 7 
#define DHTTYPE DHT11

// DHT instance
DHT dht(DHTPIN, DHTTYPE);

// Enter a MAC address for your controller below.
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0x00, 0x00 };

// IP address in case DHCP fails
IPAddress ip(192,168,1,154);

// Ethernet server
EthernetServer server(80);

// Create aREST instance
aREST rest = aREST();

void setup(void)
{  
  // Start Serial
  Serial.begin(115200);
  
   // Init DHT
  dht.begin();

  // Give name and ID to device
  rest.set_id("009");
  rest.set_name("lamp_control");

  // Start the Ethernet connection and the server
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  // Start watchdog
  wdt_enable(WDTO_4S);
}

void loop() {  

  //temp = (float)dht.readTemperature();
  //hum = (float)dht.readHumidity();
  
  // Measure light level
  //float sensor_reading = analogRead(A0);
  //light = (sensor_reading/1024*100);
  
  // listen for incoming clients
  EthernetClient client = server.available();
  rest.handle(client);
  wdt_reset();
  
}

// Custom function accessible by the API
int ledControl(String command) {
  
  // Get state from command
  int state = command.toInt();
  
  digitalWrite(6,state);
  return 1;
}
