const int buttonPin = 2;     // the number of the input sensor pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Serial.println(buttonState);
    Serial.println("The recipient is fulled");
    digitalWrite(ledPin, HIGH);
    delay(1000);
  }
  else {
    digitalWrite(ledPin, LOW);
    Serial.println(buttonState);
    Serial.println("The recipient is empty");
    delay(1000);
  }
}
