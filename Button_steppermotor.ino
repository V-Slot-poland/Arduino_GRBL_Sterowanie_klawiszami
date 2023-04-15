//www.v-slot.pl
// STEROWANIE SILNIKIEM KROKOWYM ZA POMOCĄ PRZYCISKU 3 POZYCYJNEGO
// 04.2023 
// DM


#include <SoftwareSerial.h>

// Przypisanie pinów
const int switchPin1 = 2; // Przełącznik - lewo
const int switchPin2 = 3; // Przełącznik - prawo

void setup() {
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  

  Serial.begin(115200); // Inicjalizacja komunikacji szeregowej
  delay(1000);;
  arduino1Serial.println("$X");
  delay(1000);
}

void loop() {
  // Odczyt stanu przełącznika
  int switchState1 = digitalRead(switchPin1);
  int switchState2 = digitalRead(switchPin2);

  // Wysłanie komendy do Arduino 1 w zależności od stanu przełącznika
  if (switchState1 == LOW) {
    // Obrót w lewo
    Serial.println("G0 X-1 F3500");
    Serial.println("lewo");
  } else if (switchState2 == LOW) {
    // Obrót w prawo
    Serial.println("G0 X+1 F3500");
    Serial.println("prawo");
  } else {
  
  }

  delay(100); // Krótka przerwa przed kolejnym odczytem stanu przełącznika
}
