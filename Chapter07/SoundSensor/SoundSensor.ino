//The program below shows how to use the sound sensor to control the led. Connect the Sound sensor to analog port A0 and the LED to port 12.
//The potentiometer is used to regulate the gain of the output signal. 
//The larger the potentiometer, the larger the output signal. If the sound of the environment is bigger than the threshold, then the Led will be turned on.

const int ledPin =  12;         // the number of the LED pin
const int thresholdvalue = 400; //The threshold to turn the led on

void setup() {
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
}
  
void loop() {
  int sensorValue = analogRead(A0);   //use A0 to read the electrical signal
  Serial.print("Noise detected=");
  Serial.println(sensorValue);
  delay(100);
  if(sensorValue > thresholdvalue)
  digitalWrite(ledPin,HIGH);//if the value read from A0 is larger than 400,then light the LED
  delay(200);
  digitalWrite(ledPin,LOW);
  
}
