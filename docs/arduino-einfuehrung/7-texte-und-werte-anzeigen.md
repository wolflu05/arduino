# 7. Texte und Werte anzeigen

## 7.1 Was zeigt das Programm an?

Das Programm wird folgendes in der seriellen Konsole anzeigen:

```arduino
Dieses kurze Gedicht
endet
nicht
nicht
nicht
nicht
...
```

## 7.2 Gesichter in der Konsole

Dieses Programm schreibt ein lachendes und ein trauriges Gesicht in die Konsole.

[Gesichter.ino]({GITHUB}/programme/ArduinoEinfuehrung/7.2_Gesichter/Gesichter.ino ':include :type=code arduino :link :wrap :open')

## 7.3 Variablenüberlauf

Wenn man ein Programm ausführt, dass eine Variable unbegrenzt erhöht, kann man etwas seltsames beobachten:

[Variablenueberlauf.ino]({GITHUB}/programme/ArduinoEinfuehrung/7.3_Variablenueberlauf/Variablenueberlauf.ino ':include :type=code arduino :link :wrap :open')

```arduino
32762
32763
32764
32765
32766
32767
-32768
-32767
-32766
-32765
```

Man sieht, dass der Arduino nur bis $32767$ zählt und dann wieder von vorne also $-32765$ anfängt. Das liegt daran, dass
ein Integer nur 16bit (2byte) zum speichern bekommt. Deswegen kann er keine größeren Zahlen als von $-2^{15}$ bis
$(2^{15})–1$ speichern. Das Verhalten kann man dadurch begründen, dass der Arduino die Zahlen binär addiert und nach
$111111111111111$ wieder von vorne also $000000000000000$ anfängt. Der Arduino nutzt dafür eine Technik, namens
Zweierkomplement um die Zahl zu speichern. Diese Art zu rechnen nennt sich auch Modulorechnen.
