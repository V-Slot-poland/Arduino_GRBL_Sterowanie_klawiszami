/**
 * Arduino GRBL - Sterowanie Przyciskami
 *
 * Projekt: Arduino GRBL Sterowanie klawiszami
 * Autor: DM
 * Organizacja: V-Slot Poland (www.v-slot.pl)
 * Data: 04.2023 | Zaktualizowano: 07.2024
 *
 * Opis:
 * Skrypt steruje silnikami krokowymi za pomocą przełącznika 3-pozycyjnego.
 * Przesyła komendy G-code do sterownika GRBL poprzez komunikację szeregową.
 *
 * Hardware: Arduino Uno/Mega/Nano + Przełącznik 3-pozycyjny
 */

// ============================================================================
// KONFIGURACJA
// ============================================================================

// Przypisanie pinów
const int switchPin1 = 2;  // Pin lewego przełącznika
const int switchPin2 = 3;  // Pin prawego przełącznika

// Parametry komunikacji
const unsigned long BAUD_RATE = 115200;  // Prędkość transmisji
const unsigned long INIT_DELAY = 1000;   // Opóźnienie inicjalizacji
const unsigned long LOOP_DELAY = 100;    // Debouncing delay

// Komendy G-code
const char* CMD_CLEAR_ALARM = "$X";
const char* CMD_MOVE_LEFT = "G0 X-1 F3500";
const char* CMD_MOVE_RIGHT = "G0 X+1 F3500";

// ============================================================================
// SETUP - Inicjalizacja
// ============================================================================

void setup() {
  // Konfiguracja pinów wejściowych z pull-up rezystorami
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);

  // Inicjalizacja komunikacji szeregowej z GRBL
  Serial.begin(BAUD_RATE);

  // Czekaj na stabilizację sterownika
  delay(INIT_DELAY);

  // Wyślij komendę wyczyszczenia alarmu do GRBL
  Serial.println(CMD_CLEAR_ALARM);

  delay(INIT_DELAY);
}

// ============================================================================
// LOOP - Główna pętla programu
// ============================================================================

void loop() {
  // Odczyt aktualnego stanu przełączników
  // LOW = naciśnięty (0V), HIGH = zwolniony (5V)
  int switchState1 = digitalRead(switchPin1);
  int switchState2 = digitalRead(switchPin2);

  // Sprawdzenie lewego przełącznika
  if (switchState1 == LOW) {
    // Przełącznik LEWO jest naciśnięty - wyślij komendę ruchu
    Serial.println(CMD_MOVE_LEFT);
    Serial.println("lewo");  // Log dla debugowania
  }
  // Sprawdzenie prawego przełącznika
  else if (switchState2 == LOW) {
    // Przełącznik PRAWO jest naciśnięty - wyślij komendę ruchu
    Serial.println(CMD_MOVE_RIGHT);
    Serial.println("prawo");  // Log dla debugowania
  }
  // Żaden przełącznik nie jest naciśnięty
  else {
    // Brak akcji - czekaj na kolejne naciśnięcie
  }

  // Opóźnienie debouncing
  // - Ochrona przed wielokrotnym odczytem
  // - Stabilność komunikacji szeregowej
  // - Ochrona sterownika GRBL przed zbyt wieloma komendami
  delay(LOOP_DELAY);
}

// ============================================================================
// KONIEC SKRYPTU
// ============================================================================
