# Arduino GRBL - Sterowanie Przyciskami 🎮

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/Platform-Arduino-brightgreen.svg)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)

Kontroler do sterowania silnikami krokowymi poprzez 3-pozycyjny przełącznik, przeznaczony do pracy z systemami GRBL. Projekt pozwala na bezprzewodową kontrolę maszyn CNC, grawerów i ploterów.

## 🌟 Główne Cechy

- **Kompatybilność GRBL** - Pełna obsługa poleceń G-code dla systemów CNC
- **Prostota** - Minimalne wymagania sprzętowe i konfiguracyjne
- **Niezawodność** - Stabilna komunikacja szeregowa z Arduino
- **Łatwość użytkowania** - Intuicyjne sterowanie 3-pozycyjnym przełącznikiem
- **Open Source** - Licencja MIT, pełny dostęp do kodu

## 📋 Wymagania

### Sprzęt
- Arduino Uno / Arduino Mega / Arduino Nano
- Przełącznik 3-pozycyjny (lewo-środek-prawo)
- Kabel USB do Arduino
- Sterownik/Układ silnika krokowego
- Zasilacz 5V dla Arduino

### Oprogramowanie
- Arduino IDE (wersja 1.8.13+)
- Sterowniki CH340G (jeśli używasz klonów Arduino)
- Terminal szeregowy (np. Arduino IDE, PuTTY)

## 🚀 Szybki Start

### 1. Instalacja Sprzętu

```
Przełącznik (3-pozycyjny)
    ↓
Arduino Pin 2 (Lewo) ← Przełącznik
Arduino Pin 3 (Prawo) ← Przełącznik
```

**Schemat podłączenia:**

```
GND (Przełącznik) → GND (Arduino)
Lewo → Pin 2 (INPUT_PULLUP)
Prawo → Pin 3 (INPUT_PULLUP)
```

### 2. Instalacja Kodu

1. Otwórz Arduino IDE
2. Otwórz plik `Button_steppermotor.ino`
3. Ustaw planszę: Tools → Board → Arduino Uno
4. Ustaw port COM: Tools → Port
5. Kliknij Upload (Ctrl + U)

### 3. Testowanie

Otwórz Serial Monitor (Ctrl + Shift + M):
- Baud Rate: 115200
- Naciśnij przełącznik w lewo - powinna się wyświetlić `lewo`
- Naciśnij przełącznik w prawo - powinna się wyświetlić `prawo`

## 📖 Dokumentacja

- [INSTALL.md](./INSTALL.md) - Szczegółowa instrukcja instalacji
- [USAGE.md](./USAGE.md) - Przewodnik użytkownika i konfiguracja
- [TECHNICAL.md](./TECHNICAL.md) - Dokumentacja techniczna
- [CHANGELOG.md](./CHANGELOG.md) - Historia zmian

## 🔧 Konfiguracja

### Dostępne Parametry

```cpp
const int switchPin1 = 2;      // Pin dla lewego przełącznika
const int switchPin2 = 3;      // Pin dla prawego przełącznika
const int baudRate = 115200;   // Prędkość komunikacji szeregowej
const int delayTime = 100;     // Opóźnienie odczytu (ms)
```

### Dostępne Komendy G-code

```
G0 X-1 F3500  → Ruch w lewo
G0 X+1 F3500  → Ruch w prawo
$X            → Wyczyszczenie błędów systemu
```

## 📁 Struktura Projektu

```
Arduino_GRBL_Sterowanie_klawiszkami/
├── Button_steppermotor.ino       # Główny kod Arduino
├── README.md                      # Ten plik
├── INSTALL.md                     # Instrukcja instalacji
├── USAGE.md                       # Przewodnik użytkownika
├── TECHNICAL.md                   # Dokumentacja techniczna
├── CHANGELOG.md                   # Historia zmian
├── LICENSE                        # Licencja MIT
└── examples/                      # Przykładowe kody
```

## 🎯 Przykłady Zastosowań

- **Maszyny CNC** - Sterowanie ruchem X, Y lub Z
- **Grawerki laserowe** - Kontrola pozycjonowania
- **Plotery** - Precyzyjne sterowanie ruchem
- **Drukarka 3D** - Ruch głowicy drukującej
- **Powiększarka fotograficzna** - Automatyczne pozycjonowanie

## 🐛 Rozwiązywanie Problemów

### Arduino nie odpowiada
- Sprawdź połączenie USB
- Upewnij się, że wybrałeś poprawny port COM
- Zainstaluj sterowniki CH340G

### Przełącznik nie działa
- Sprawdź podłączenie pinów (Pin 2 i 3)
- Upewnij się, że używasz INPUT_PULLUP
- Przetestuj przełącznik multimetrem

### Komendy G-code nie są wykonywane
- Sprawdź prędkość transmisji (115200 baud)
- Upewnij się, że sterownik GRBL jest odpowiednio skonfigurowany
- Załaduj domyślne ustawienia GRBL (`$RST=*`)

## 🤝 Contributing

Zapraszamy do współpracy! Jeśli masz pomysły na ulepszenia:

1. Fork projekt
2. Stwórz gałąź (`git checkout -b feature/AmazingFeature`)
3. Skomituj zmiany (`git commit -m 'Add some AmazingFeature'`)
4. Push do gałęzi (`git push origin feature/AmazingFeature`)
5. Otwórz Pull Request

## 📄 Licencja

Ten projekt jest licencjonowany na warunkach licencji MIT - zobacz plik [LICENSE](./LICENSE) po szczegóły.

## 👨‍💻 Autorzy

- **DM** - Główny autor - [V-Slot Poland](https://www.v-slot.pl/)

## 📞 Kontakt i Wsparcie

- 📧 Email: support@v-slot.pl
- 🌐 Strona: https://www.v-slot.pl/
- 💬 Issues: [GitHub Issues](https://github.com/V-Slot-poland/Arduino_GRBL_Sterowanie_klawiszami/issues)

---

**Ostatnia aktualizacja:** Lipiec 2024
**Wersja:** 2.0.0
