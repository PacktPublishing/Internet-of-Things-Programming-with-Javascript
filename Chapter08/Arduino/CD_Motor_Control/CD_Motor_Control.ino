#include <MeetAndroid.h>
#include <LiquidCrystal.h>  // incluir la libreria para LCD

LiquidCrystal lcd(12,11,5,4,3,2); 
MeetAndroid meetAndroid;

//configuracion de pines del arduino
int EN1 = 9;
int IN1 = 7;
int IN2 = 8;
int pin = 13;
int pwm;

void setup()  
{
   delay(500);        // pausa requerida para inicializar el lcd
   lcd.begin(16, 2);  // selecciona el número de renglones y columnas 
   Serial.begin(9600);
   
   lcd.setCursor(0, 0);
   lcd.print("    Motor CD   "); 
   lcd.setCursor(0, 1);
   lcd.print("Arduino-Android");

meetAndroid.registerFunction(Izquierda, 'i');  //funcion se mueve motor adelante
meetAndroid.registerFunction(Derecha, 'd');     //funcion se mueve motor atras
meetAndroid.registerFunction(Detener, 's');   //funcion se detiene motor
meetAndroid.registerFunction(Velocidad, 'v'); //control de velocidad motor

// Configuramos las terminales del arduino
// EN1 pin 1 del puente H va conectado al pin 11 del arduino (PWM) para control de la velocidad
// IN1 y IN2 son los pines del arduino (7 y 8) el 7 se conecta al 7 del puente H
// el pin No. 8 se conecta al 2 del puente h para control del giro
// van conectados configurados como salidas todos

pinMode(pin,OUTPUT);
pinMode(EN1,OUTPUT);

pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
digitalWrite(pin,LOW);
}

void loop()
{
  meetAndroid.receive();
}
void Velocidad(byte flag, byte numOfValues)
{
  //Con esta instrucción le estamos diciendo al Arduino
  //Que va a recibir el valor enviado desde Android
  //Por el pin No. 9 va a enviar el valor PWM recibido
    
  pwm = meetAndroid.getInt();
  analogWrite(EN1,pwm);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Motor -ON- ");
  lcd.setCursor(0, 1);
  lcd.print("    PWM = ");
  lcd.print(pwm);
  }
  
void Izquierda(byte flag, byte numOfValues)
{
  pwm = meetAndroid.getInt();
  analogWrite(EN1,pwm);
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Motor -ON- ");
  lcd.setCursor(0, 1);
  lcd.print("    PWM = ");
  lcd.print(pwm);
}

void Derecha(byte flag, byte numOfValues)
{
  pwm = meetAndroid.getInt();
  analogWrite(EN1,pwm);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Motor -ON- ");
  lcd.setCursor(0, 1);
  lcd.print("    PWM = ");
  lcd.print(pwm);
}

void Detener(byte flag, byte numOfValues)
{
  pwm = meetAndroid.getInt();
  analogWrite(EN1,pwm);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Motor OFF   ");
  lcd.setCursor(0, 1);
  lcd.print("    PWM = ");
  lcd.print(pwm);
  delay(3000);
  
  lcd.setCursor(0, 0);
  lcd.print("    Motor CD   "); 
  lcd.setCursor(0, 1);
  lcd.print("Arduino-Android");
}




