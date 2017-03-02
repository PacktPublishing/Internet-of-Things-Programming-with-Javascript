int load = 10; 
int intensity = 128;

void setup()
{
pinMode(loaf, OUTPUT);
attachInterrupt(0, cross_zero_int, RISING);
}

void loop()
{
intensity = map(analogRead(0),0,1023,10,128); // escala valor analógico de 0-1023 a 10-128
}

void cross_zero_int()
{
int dimtime = (65 * intensity); 
delayMicroseconds(dimtime); 
digitalWrite(load, HIGH); 
delayMicroseconds(8); 
digitalWrite(load, LOW);
}
