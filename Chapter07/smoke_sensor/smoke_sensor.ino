const int sensorPin= 0;
const int buzzerPin= 12;
int smoke_level;

void setup() {
Serial.begin(115200); //sets the baud rate for data transfer in bits/second
pinMode(sensorPin, INPUT);//the smoke sensor will be an input to the arduino
pinMode(buzzerPin, OUTPUT);//the buzzer serves an output in the circuit
}

void loop() {
smoke_level= analogRead(sensorPin); //arduino reads the value from the smoke sensor
Serial.println(smoke_level);//prints just for debugging purposes, to see what values the sensor is picking up

if(smoke_level > 200){ //if smoke level is greater than 200, the buzzer will go off
digitalWrite(buzzerPin, HIGH);
}

else{
digitalWrite(buzzerPin, LOW);
}
}
