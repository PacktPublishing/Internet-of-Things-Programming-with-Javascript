#include <MFRC522.h>
#include <SPI.h>
#define SAD 10
#define RST 5

MFRC522 nfc(SAD, RST);

#define ledPinOpen  2
#define ledPinClose 3

void setup() {
  pinMode(ledPinOpen,OUTPUT);   
  pinMode(ledPinClose,OUTPUT);   
  SPI.begin();
  Serial.begin(115200);
  Serial.println("Looking for RC522");
  nfc.begin();
  byte version = nfc.getFirmwareVersion();

  if (! version) {
    Serial.print("We don't find RC522");
    while(1);
  }
  Serial.print("Found RC522");
  Serial.print("Firmware version 0x");
  Serial.print(version, HEX);
  Serial.println(".");
}

#define AUTHORIZED_COUNT 2 //number of cards Authorized
byte Authorized[AUTHORIZED_COUNT][6] = {{0xC6, 0x95, 0x39, 0x31, 0x5B},{0x2E, 0x7, 0x9A, 0xE5, 0x56}};
                           
                          
void printSerial(byte *serial);
boolean isSame(byte *key, byte *serial);
boolean isAuthorized(byte *serial);

void loop() {
  byte status;
  byte data[MAX_LEN];
  byte serial[5];
  boolean Open = false;
  digitalWrite(ledPinOpen, Open);
  digitalWrite(ledPinClose, !Open);
  status = nfc.requestTag(MF1_REQIDL, data);

  if (status == MI_OK) {
    status = nfc.antiCollision(data);
    memcpy(serial, data, 5);
    
    if(isAuthorized(serial))
    { 
      Serial.println("Access Granted");
      Open = true;
    }
    else
    { 
      printSerial(serial);
      Serial.println("NO Access");
      Open = false;
    }
    
    nfc.haltTag();
    digitalWrite(ledPinOpen, Open);
    digitalWrite(ledPinClose, !Open);
    delay(2000);
    
  }//if (status == MI_OK)
  delay(500);

}//void loop()

boolean isSame(byte *key, byte *serial)
{
    for (int i = 0; i < 4; i++) {
      if (key[i] != serial[i])
      { 
        return false; 
      }
    }
    return true;
}

boolean isAuthorized(byte *serial)
{
    for(int i = 0; i<AUTHORIZED_COUNT; i++)
    {
      if(isSame(serial, Authorized[i]))
        return true;
    }
   return false;
}
void printSerial(byte *serial)
{
    Serial.print("Serial:");
    for (int i = 0; i < 5; i++) {
    Serial.print(serial[i], HEX);
    Serial.print(" ");
    }
}
