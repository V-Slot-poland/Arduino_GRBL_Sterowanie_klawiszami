# Instrukcja Instalacji 📦

Kompletny przewodnik do zainstalowania Arduino GRBL Sterowania Klawiszami.

## Szybki Start

### 1. Wymagania
- Arduino IDE: https://www.arduino.cc/en/software
- Arduino Uno/Mega/Nano
- Przełącznik 3-pozycyjny
- Kabel USB

### 2. Instalacja Arduino IDE

**Windows:**
1. Pobierz Arduino IDE z https://www.arduino.cc/en/software
2. Uruchom instalator
3. Zainstaluj (domyślne ustawienia OK)

**macOS/Linux:**
```bash
# macOS (Homebrew)
brew install arduino

# Linux (Ubuntu/Debian)
sudo apt install arduino
```

### 3. Instalacja Kodu

1. Otwórz Arduino IDE
2. File → Open → Button_steppermotor.ino
3. Tools → Board → Arduino Uno
4. Tools → Port → COM3 (twój port)
5. Sketch → Upload (Ctrl + U)

### 4. Testowanie

1. Tools → Serial Monitor (Ctrl + Shift + M)
2. Baud Rate: 115200
3. Naciśnij przełącznik - powinno się wyświetlić "lewo" lub "prawo"

## Rozwiązywanie Problemów

### Port COM nie widoczny
- Zainstaluj sterownik CH340G: https://sparks.gogo.co.nz/ch340.html
- Uruchom ponownie IDE

### Compilation Error
- Sprawdź numery pinów w kodzie
- Przeinstaluj Arduino IDE

### Arduino się nie komunikuje
- Sprawdź baud rate (115200)
- Sprawdź połączenie USB

## Szczegółowa Dokumentacja

Przeczytaj [USAGE.md](./USAGE.md) dla konfiguracji zaawansowanej.

---

**Ostatnia aktualizacja:** Lipiec 2024
