#include <SoftwareSerial.h>

// Przypisanie pinów
const int switchPin1 = 2; // Przełącznik - lewo
const int switchPin2 = 3; // Przełącznik - prawo
const int rxPin = 8;
const int txPin = 9;

SoftwareSerial arduino1Serial(rxPin, txPin); // Komunikacja z Arduino 1 za pomocą pinów RX/TX

void setup() {
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  Serial.begin(115200); // Inicjalizacja komunikacji szeregowej
  arduino1Serial.begin(115200); // Inicjalizacja komunikacji szeregowej z Arduino 1
  //Serial.println("URUCHOMIONO");
  delay(1000);;
  //arduino1Serial.println("$X");
  delay(1000);
}

void loop() {
  // Odczyt stanu przełącznika
  int switchState1 = digitalRead(switchPin1);
  int switchState2 = digitalRead(switchPin2);

  // Wysłanie komendy do Arduino 1 w zależności od stanu przełącznika
  if (switchState1 == LOW) {
    // Obrót w lewo
    Serial.println("G91 G0 X-1");
    Serial.println("lewo");
  } else if (switchState2 == LOW) {
    // Obrót w prawo
    Serial.println("G91 G0 X1");
    Serial.println("prawo");
  } else {
  
  }

  delay(100); // Krótka przerwa przed kolejnym odczytem stanu przełącznika
}
