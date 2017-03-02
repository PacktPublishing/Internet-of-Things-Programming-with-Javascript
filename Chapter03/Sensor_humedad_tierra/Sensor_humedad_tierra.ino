int Valor;  

void setup() {
Serial.begin(9600);
} 

void loop(){  
Serial.print("Huminity sensor value:");
Valor = analogRead(0);  
Serial.print(Valor);  
 
if (Valor <= 300)  
   Serial.println(" Very wet");  
if ((Valor > 300) and (Valor <= 700))  
    Serial.println(" Wet, do not water");   
if (Valor > 700)  
    Serial.println(" Dry, you need to water"); 
    delay(1000); 
} 
