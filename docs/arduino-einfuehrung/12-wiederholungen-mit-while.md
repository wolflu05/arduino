# 12 Wiederholungen mit while

### 12.1 Wie läuft das Programm ab?

Das beschriebene Programm wird nie bis in die loop-Schleife kommen, da es in der while-Schleife mit einer Bedingung, die
immer wahr ist, hängen bleibt. Es wird als erstes die Zahlen von 1-99 ausgeben und dann unendlich viele `!`.

### 12.2 Was tut die leere while – Schleife?

Die leere Schleife wartet, bis die Taste an Pin 4 gedrückt wird, gibt dann `von jetzt` aus, wartet, bis der Taster
losgelassen wird und gibt dann `bis jetzt` in derselben Zeile aus.

### 12.3 Ton mit Taster

Folgendes Programm kann einen Ton erzeugen, und man kann mithilfe den 2 Tastern die Frequenz des Tones regeln. Dabei
werden 2 while - Schleifen verwendet, um im Programm so lange zu warten, bis der Taster losgelassen wurde.

[TonMitTaster.ino]({GITHUB}/programme/ArduinoEinfuehrung/12.3_TonMitTaster/TonMitTaster.ino ':include :type=code arduino :link :wrap :open')
