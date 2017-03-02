#include <Keypad.h> // incluye libreria para manejar teclado matricial.
#include <LiquidCrystal.h>  // incluye la libreria para el lcd.

LiquidCrystal lcd(14, 15, 16, 17, 18, 19); // (RS,E,D4,D5,D6,D7)

const byte ROWS = 4; // define constante ROWS (renglones) = 4.
const byte COLS = 4; // define constante COLS (columnas) = 4.

// Establece las etiquetas de los botones del teclado.
byte hexaKeys[ROWS][COLS] = 
{
  {1,2,3,'A'},
  {4,5,6,'B'},
  {7,8,9,'C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {11, 10, 9, 8}; // pines del arduino conectados a los renglones 11(R1),10(R2),9(R3),8(R4).
byte colPins[COLS] = {7, 6, 5, 4}; // pines del arduino conectados a las columnas 7(C1),6(C2),5(C3),4(C4).

//inicializa el teclado.
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

// asignación de variables
int led =13;  // asigna pin de arduino conectado a un LED (led de fábrica).
int digito;   // contiene la cuenta del número de digitos.
int tecla;    // contiene el valor de la tecla presionada.
unsigned int valor;   // valor a cargar.
unsigned int valorf;  // valor conformado al instante.
unsigned int valorf1; // valor captura de 1 digito.
unsigned int valorf2; // valor captura de 2 digito.
unsigned int valorf3; // valor captura de 3 digito.
unsigned int valorf4; // valor captura de 4 digito.
unsigned int valorf5; // valor captura de 5 digito.

void setup()
{
  lcd.begin(16, 2); // número de columnas y renglones.
  lcd.clear();  // limpia pantalla LCD.
  pinMode(led,OUTPUT);
  valorf=0;
  // muestra mensaje inicial en LCD.
  lcd.setCursor(0,0);
  lcd.print(valorf);
  lcd.print("          ");
  valorf=0;
  lcd.setCursor(0,1);
  lcd.print("Aplicar Pres. * ");
}


void loop()
{
  captura();  // llama a la rutina de captura
  if (valor == 55) // si se captura el valor 55:
  {
    digitalWrite(led,HIGH); // activa el led (pin 13)
  }
  if (valor == 66) // si se captura el valor 66:
  {
    digitalWrite(led,LOW);  // apaga el led (pin 13)
  }
  analogWrite(3,valor);
}


void captura()
{
  tecla = customKeypad.getKey();
  
  if (tecla)
  {
    digito = digito + 1; // variable digito se incrementa cada vez que se presiona una tecla
    if(tecla==35){tecla=0;digito=0;valorf=0;lcd.setCursor(0,0);lcd.print(valorf);lcd.print("          ");} // tecla # función clear
    if(tecla==48){tecla=0;} // asigna el valor de 0 
    if(tecla==42){tecla=0;digito=0;valor = valorf;} // * = enter
       
    // condiciones para mostrar valor conjunta los datos obtenidos en el teclado uno a uno, para generar el valor final
    // en este ejemplo, acepta hasta 4 digitos (9999)
//-------------------------------------------------------------------------------------------------------------------------------------
    // Algoritmo para captura de digitos
    // captura el primer valor. Si el valor es de un solo digito, asigna ese valor a valorf (valor final).
    if(digito==1){valorf1 = tecla; valorf=valorf1;lcd.setCursor(0,0);lcd.print(valorf);lcd.print("          ");} 
    // si se presiona un segundo digito, suma el valor al del primer digito y lo multiplica por 10. valorf es de 2 dígitos.
    if(digito==2){valorf2 = tecla+(valorf1*10);valorf=valorf2;lcd.setCursor(0,0);lcd.print(valorf);lcd.print("          ");}
    // si se presiona un tercer digito, suma el valor al anterior de 2 digitos y lo multiplica por 10. valorf es de 3 dígitos. 
    if(digito==3){valorf3 = tecla+(valorf2*10);valorf=valorf3;lcd.setCursor(0,0);lcd.print(valorf);lcd.print("          ");}
    // si se presiona un cuarto digito, suma el valor al anterior de 3 digitos y lo multiplica por 10. valorf es de 4 dígitos.
    // como este es el último digito, reinicializa la cuenta de digitos (digito = 0).
    if(digito==4){valorf4 = tecla+(valorf3*10);valorf=valorf4;lcd.setCursor(0,0);lcd.print(valorf);lcd.print("          ");}
    if(digito==5){valorf5 = tecla+(valorf4*10);valorf=valorf5;lcd.setCursor(0,0);lcd.print(valorf);lcd.print("          ");digito=0;}
//-------------------------------------------------------------------------------------------------------------------------------------    
  }
}


