# 14. LCD Display

### 14.1 Bibliothek installieren

Um ein LCD - Display anzusteuern müsste man viel zu viele Befehle nutzen. Deswegen hat sich jemand anders die Mühe
gemacht und mehrere Funktionen dafür geschrieben. Diese Funktionen zusammen kann man in einem Paket einer sogenannten
Bibliothek herunterladen. Um diese Bibliothek herunterzuladen geht man auf
`Sketch –> Bibliothek einbinden –> Bibliotheken verwalten` oder alternativ drückt man `Strg + Umschalt + I`. Dann sucht
man nach dem Namen `LiquidCrystal I2C` und drückt auf installieren. Hat man das geschafft, kann man weiter machen.

### 14.2 Kontrast einstellen

Mithilfe des Potis auf der Rückseite lässt sich der Kontrast des Displays regulieren.

### 14.3 Was macht das Programm

In meinem Fall ist die I2C Adresse nicht `0x27` sondern `0x3f`. Dieses Programm zeigt auf dem LCD-Display
`Zeit: <Die vergangene Zeit in Millisekunden seit dem Start des Arduino>` an. Mit den Befehlen `Lcd.backlight();` und
`Lcd.noBacklight();` kann man die Hintergrundbeleuchtung ein/-ausschalten.

[LCDDisplay.ino]({GITHUB}/programme/ArduinoEinfuehrung/14.3_LCDDisplay/LCDDisplay.ino ':include :type=code arduino :link :wrap :open')
