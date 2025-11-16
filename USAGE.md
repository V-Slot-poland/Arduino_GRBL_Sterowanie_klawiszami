# Przewodnik Użytkownika 📖

## Obsługa Podstawowa

### Uruchomienie

1. Włącz Arduino (USB lub zasilanie)
2. Serial Monitor: Tools → Serial Monitor (Ctrl + Shift + M)
3. Baud Rate: **115200**
4. Testuj przełącznik

### Sterowanie

```
Przełącznik:
  [←] Naciśnij LEWO  → wysyła: G0 X-1 F3500
  [·] Środek (brak akcji)
  [→] Naciśnij PRAWO → wysyła: G0 X+1 F3500
```

## Konfiguracja

### Zmiana Pinów

W pliku `Button_steppermotor.ino`:

```cpp
const int switchPin1 = 2;  // Pin LEWO
const int switchPin2 = 3;  // Pin PRAWO
```

Zmień na swoje piny i przesyłaj do Arduino.

### Zmiana Prędkości

```cpp
const char* CMD_MOVE_LEFT = "G0 X-1 F3500";   // F3500 = prędkość
```

Zmień F3500 na inną wartość (min 1000, max 5000).

### Zmiana Komendy G-code

```cpp
const char* CMD_MOVE_LEFT = "G0 X-1 F3500";   // Ruch X
// Zmień na:
const char* CMD_MOVE_LEFT = "G0 Y-1 F3500";   // Ruch Y
const char* CMD_MOVE_LEFT = "G0 Z-1 F3500";   // Ruch Z
```

## Zaawansowane Rozszerzenia

### Dodanie Trzeciego Przycisku

```cpp
const int switchPin3 = 4;  // Nowy pin

void setup() {
  pinMode(switchPin3, INPUT_PULLUP);
  // ...
}

void loop() {
  // ... istniejący kod ...

  int switchState3 = digitalRead(switchPin3);
  if (switchState3 == LOW) {
    Serial.println("G0 Z-1 F3500");
  }
}
```

### Kontrola Prędkości za Potencjometrem

```cpp
const int potPin = A0;

void loop() {
  int potValue = analogRead(potPin);
  int speed = map(potValue, 0, 1023, 1000, 5000);

  if (switchState1 == LOW) {
    Serial.print("G0 X-1 F");
    Serial.println(speed);
  }
}
```

## Dostępne Komendy GRBL

```
G0 X1      - Ruch szybki na X+1
G0 Y-5     - Ruch szybki na Y-5
G0 Z0.5    - Ruch szybki na Z+0.5
G0 X1 Y1   - Ruch jednoczesny
$X         - Wyczyszczenie alarmu
$H         - Home (przywrócenie do zera)
$$         - Wyświetl wszystkie ustawienia
```

## Debugowanie

### Serial Monitor Output

```
$X
Arduino initialized
lewo      ← Przełącznik wciśnięty
prawo     ← Przełącznik wciśnięty
```

### Jeśli Nic Się Nie Wysyła

1. Sprawdź baud rate (115200)
2. Sprawdź port COM
3. Sprawdź połączenie USB
4. Naciśnij RESET na Arduino

## FAQ

**P: Jak zmienić dystans ruchu?**
```cpp
G0 X-1      // zmień 1 na inną wartość (0.5, 5, 10)
G0 X-0.5    // mały ruch
G0 X-10     // duży ruch
```

**P: Jak zmienić prędkość?**
```cpp
F3500   // zmień na F1000 (wolno), F5000 (szybko)
```

**P: Czy mogę dodać więcej przełączników?**
Tak! Zobacz sekcję "Rozszerzenia" wyżej.

---

**Ostatnia aktualizacja:** Lipiec 2024
