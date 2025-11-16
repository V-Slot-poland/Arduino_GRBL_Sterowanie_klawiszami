# Arduino GRBL Sterowanie Klawiszami 🎮

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Arduino](https://img.shields.io/badge/Platform-Arduino-brightgreen.svg)](https://www.arduino.cc/)
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)]()

Prosty i niezawodny sterownik do kontroli maszyn CNC, grawerów i ploterów za pomocą przełącznika 3-pozycyjnego.

## 🚀 Szybki Start

```bash
# 1. Pobierz kod
git clone https://github.com/V-Slot-poland/Arduino_GRBL_Sterowanie_klawiszami.git

# 2. Otwórz w Arduino IDE
# File → Open → Button_steppermotor.ino

# 3. Konfiguruj Arduino
# Tools → Board → Arduino Uno
# Tools → Port → COM3

# 4. Wgraj kod
# Ctrl + U (Upload)
```

## ✨ Główne Cechy

- ✅ **Proste** - Łatwe do instalacji i konfiguracji
- ✅ **Niezawodne** - Stabilna komunikacja szeregowa
- ✅ **Elastyczne** - Łatwo dostosowalne do potrzeb
- ✅ **Dokumentowane** - Kompletna dokumentacja
- ✅ **Open Source** - MIT License

## 📚 Dokumentacja

- 📖 [README](./README.md) - Przegląd projektu
- 🔧 [INSTALL.md](./INSTALL.md) - Instrukcja instalacji
- 📖 [USAGE.md](./USAGE.md) - Przewodnik użytkownika
- 🔬 [TECHNICAL.md](./TECHNICAL.md) - Dokumentacja techniczna
- 🤝 [CONTRIBUTING.md](./CONTRIBUTING.md) - Jak współtwórować

## 💻 Wymagania

- Arduino Uno/Mega/Nano
- Przełącznik 3-pozycyjny
- Arduino IDE 1.8.13+
- Kabel USB

## 📋 Przykłady

```cpp
// Wysłanie komendy do GRBL
Serial.println("G0 X-1 F3500");  // Ruch w lewo

// Odczyt przełącznika
int state = digitalRead(switchPin);
if (state == LOW) {
  Serial.println("Przełącznik naciśnięty!");
}
```

## 🎯 Use Cases

- Maszyny CNC
- Grawerki Laserowe
- Plotery
- Drukarki 3D
- Maszyny Tekstylne

## 🐛 Znalazłeś Bug?

[Otwórz Issue](https://github.com/V-Slot-poland/Arduino_GRBL_Sterowanie_klawiszami/issues)

## 💡 Masz Pomysł?

[Zasugeruj Funkcję](https://github.com/V-Slot-poland/Arduino_GRBL_Sterowanie_klawiszami/discussions)

## 🤝 Chcesz Współpracować?

Przeczytaj [CONTRIBUTING.md](./CONTRIBUTING.md)

## 📄 Licencja

MIT License - Patrz [LICENSE](./LICENSE)

## 🙏 Podziękowania

- Arduino Community
- GRBL Developers
- V-Slot Poland

---

⭐ Jeśli projekt Ci się podoba, daj gwiazdkę! ⭐
