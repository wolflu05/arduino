# 15. Motor steuern

Da wir keine solche Motorsteuerplatine zur Steuerung haben, verwenden wir den L293D Chip direkt und bauen die folgende
Schaltung selber auf. Um einen Motor anzusteuern ist es empfehlenswert, ein externes Netzteil zu verwenden, um die
USB-Buchse des PCs nicht zu stark zu belasten.

![Motor Schaltung](../_media/arduino-einfuehrung/schaltungen/MotorArduino_named.png)

## 15.1 Ersten Motor steuern

Dieses Programm lässt den Motor für 2 Sekunden laufen, schaltet ihn wieder 2 Sekunden aus, 2 Sekunden an, ... Dabei
schaltet man zuerst den Motor frei `digitalWrite(ENABLE, HIGH);`, setzt Richtung 2 auf `LOW` und Richtung 1 immer wieder
ein und aus.

[MotorSteuern.ino]({GITHUB}/programme/ArduinoEinfuehrung/15.1_MotorSteuern/MotorSteuern.ino ':include :type=code arduino :link :wrap :open')

## 15.2 Motor in verschiedene Richtungen drehen

Will man den Motor nun in zwei verschiedene Richtungen drehen, muss man beachten, dass man den Motor beschädigen kann,
falls man versucht beide Richtungen auf `HIGH` zu setzen. In diesen Programm gibt es für alle Richtungen (Vorwärts,
Rückwärts und Stopp) ein Unterprogramm.

[MotorSteuernUnterprogramme.ino]({GITHUB}/programme/ArduinoEinfuehrung/15.2_UnterprogrammeFuerMotor/MotorSteuernUnterprogramme.ino ':include :type=code arduino :link :wrap :open')
