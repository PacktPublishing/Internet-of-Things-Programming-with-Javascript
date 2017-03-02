int ledPin = 13;                // led
int inputPin = 2;               // Sensor PIR
int val = 0;                    // variable para ver el estado del PIR
int pinSpeaker = 10;           // Set up a speaker on a PWM pin (digital 9, 10, or 11)
int pirState = HIGH;             // empezamos asumiento que no hay fuego
 
void setup() {
  pinMode(ledPin, OUTPUT);      // salida del LED
  pinMode(inputPin, INPUT);     // salida del SENSOR
  pinMode(pinSpeaker, OUTPUT);  // speaker
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // lee si hay fuego  val=1/HIGH no hay fuego; val = 0/LOW si hay fuego
  Serial.print("val : ");  Serial.println(val);
  digitalWrite(ledPin, HIGH);  // turn LED ON para saber que el sistema esta andando
 
  if (val == HIGH) {            
       // NO hay fuego
             Serial.print("NO Fire detected ");
      digitalWrite(ledPin, LOW); // turn LED OFF
      playTone(0, 0);
      delay(300); //era 300    
  }else{
       //SI  hay fuego
             Serial.print("Fire DETECTED ");
       digitalWrite(ledPin, HIGH);  
       playTone(300, 160);
       delay(150);
  }
}
// duration in mSecs, frequency in hertz
void playTone(long duration, int freq) {
    duration *= 1000;
    int period = (1.0 / freq) * 1000000;
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(pinSpeaker,HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(pinSpeaker, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }
}
