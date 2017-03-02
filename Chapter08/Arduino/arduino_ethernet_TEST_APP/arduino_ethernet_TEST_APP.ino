// Libraries
#include <SPI.h>
#include <Ethernet.h>
#include <aREST.h>

// Enter a MAC address for your controller below.
byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x0A, 0xC2 };

// IP address in case DHCP fails
IPAddress ip(192,168,1,150);

// Ethernet server
EthernetServer server(80);

// Create aREST instance
aREST rest = aREST();

// Variables to be exposed to the API
int temperature;
int humidity;

void setup()
{
  // Start Serial
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  //digitalWrite(7,LOW);

  // Init variables and expose them to REST API
  temperature = 24;
  humidity = 40;
  rest.variable("temperature",&temperature);
  rest.variable("humidity",&humidity);

  // Give name and ID to device
  rest.set_id("1");
  rest.set_name("APPInventor");

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

}

void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  rest.handle(client);

}
