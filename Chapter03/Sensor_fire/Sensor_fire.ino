// Lecturas mínimas y máximas del sensor:
const int sensorMin = 0;     // lectura mínima
const int sensorMax = 1024;  // lectura máxima

void setup() {
  // Inicialización del puerto seria a @ 9600 baud:
  Serial.begin(9600);  
}
void loop() {
  // Leer el sensor en el pin A2:
	int sensorReading = analogRead(A2);
 
  // Mapeamos el rango del sensor (4 opciones):
  // f¿Función: 'long int map(long int, long int, long int, long int, long int)'
	int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // Valores del rango:
  switch (range) {
  case 0:    // Fuego cercano, a una distancia de aproximadamente 1.5 pies.
    Serial.println("** Fuego cercano **");
    break;
  case 1:    // Se detecta fuego entre 1-3 pies de distancia.
    Serial.println("** Fuego distante **");
    break;
  case 2:    // No se ha detectado fuego.
    Serial.println("No hay fuego");
    break;
  }
  delay(1);  // Pausa entre las lecturas.
}
