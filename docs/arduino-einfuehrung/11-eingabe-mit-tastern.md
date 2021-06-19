# 11. Eingabe mit Tastern

## 11.1 Was steht in der Konsole?

Ja, diese Aussage ist richtig, dass bei gedrücktem Taster eine `0` in der Konsole steht, da der Pin dann mit GND durch
den Taster verbunden ist.

[Taster.ino]({GITHUB}/programme/ArduinoEinfuehrung/11.1_Taster/Taster.ino ':include :type=code arduino :link :wrap :open')

## 11.2 LED mit Taster steuern

Diese Aufgabe kann man wie verlangt mit einer `if-else` - Bedingung lösen.
[TasterLED_beginner.ino]({GITHUB}/programme/ArduinoEinfuehrung/11.2_TasterLED/TasterLED_beginner/TasterLED_beginner.ino ':include :type=code arduino :link :wrap :open')

Dies geht aber noch deutlich einfacher, wenn man sich Verneinung wie in folgendem Programm ansieht.

[TasterLED_expert.ino]({GITHUB}/programme/ArduinoEinfuehrung/11.2_TasterLED/TasterLED_expert/TasterLED_expert.ino ':include :type=code arduino :link :wrap :open')
[TasterLED_expert.ino]({GITHUB}/programme/ArduinoEinfuehrung/11.2_TasterLED/TasterLED_expert/TasterLED_expert.ino ':include :type=code arduino :link :wrap :open')

## 11.3 Töne per Knopfdruck erzeugen

Wenn man einen tiefen und einen hohen Ton erzeugen will, kann man folgendes Programm nutzen. Dabei wird beim Drücken des
ersten Tasters ein Ton von 440Hz abgespielt und beim Drücken des zweiten ein Ton von 740Hz. Und wenn gar keiner gedrückt
ist, wird auch kein Ton gespielt.

[ZweiTasterLautsprecher.ino]({GITHUB}/programme/ArduinoEinfuehrung/11.3_ZweiTasterLautsprecher/ZweiTasterLautsprecher.ino ':include :type=code arduino :link :wrap :open')

## 11.4 Taster Zähler

Wenn man ein Programm schreibt, das einfach nur eine Variable hochzählt, wenn der Taster gedrückt wird, kann man
beobachten, dass die Zahl mehrfach pro Druck hochgezählt wird.

[TasterZaeler_beginner.ino]({GITHUB}/programme/ArduinoEinfuehrung/11.4_TasterZaeler/TasterZaeler_beginner/TasterZaeler_beginner.ino ':include :type=code arduino :link :wrap :open')

Dies kann man, wie wir später noch kennen lernen werden, mit einer einfachen while Schleife verhindern.

[TasterZaeler_expert.ino]({GITHUB}/programme/ArduinoEinfuehrung/11.4_TasterZaeler/TasterZaeler_expert/TasterZaeler_expert.ino ':include :type=code arduino :link :wrap :open')

## 11.5 Millis

Ja, mit diesem Programm kann man herausfinden, dass es durchschnittlich etwa 4ms braucht, um ein Zeichen auf die Konsole
zu schreiben.

[Millis.ino]({GITHUB}/programme/ArduinoEinfuehrung/11.5_Millis/Millis.ino ':include :type=code arduino :link :wrap :open')
