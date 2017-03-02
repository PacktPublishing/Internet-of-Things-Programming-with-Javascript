int readings=0;
void setup(){
Serial.begin(9600);
}

void loop(){
lectura=analogRead(A1);
Serial.print("Level of alcohol= ");
Serial.println(readings);
delay(1000);
}
