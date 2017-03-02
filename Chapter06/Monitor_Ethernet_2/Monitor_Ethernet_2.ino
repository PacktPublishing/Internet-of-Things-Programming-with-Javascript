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
byte mac[] = { 0x90, 0x00, 0x11, 0x01, 0xFE, 0x04 };

// IP address in case DHCP fails
IPAddress ip(192,168,1,156);

// Ethernet server
EthernetServer server(80);

// Create aREST instance
aREST rest = aREST();

// Variables to be exposed to the API
int temp;
int hum;
int light;

void setup(void)
{  
  // Start Serial
  Serial.begin(115200);
  
   // Init DHT
  dht.begin();

  // Init variables and expose them to REST API
  rest.variable("light",&light);
  rest.variable("temperature2",&temp);
  rest.variable("humidity2",&hum);
  
  // Give name and ID to device
  rest.set_id("011");
  rest.set_name("sensor2");

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

  temp = (float)dht.readTemperature();
  hum = (float)dht.readHumidity();
  
  // Measure light level
  float sensor_reading = analogRead(A0);
  light = (sensor_reading/1024*100);
  
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
