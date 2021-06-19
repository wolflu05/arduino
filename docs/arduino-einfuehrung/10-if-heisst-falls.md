# 10. If heißt falls

## 10.1 Schere Stein Papier

Um beim Start Schere, Stein oder Papier ausgeben zu lassen, kann man das mit 3 if-Abfragen, wie in folgendem Programm
machen.

[SchereSteinPapier.ino]({GITHUB}/programme/ArduinoEinfuehrung/10.1_SchereSteinPapier/SchereSteinPapier.ino ':include :type=code arduino :link :wrap :open')

## 10.2 Was tut das Programm?

Das angegebene Programm wird die LED an Pin 9 mit einer Helligkeit von $100$ anschalten, bis die Loop Schleife so oft
durchgelaufen ist, dass die Variable `i` größer oder gleich $100000$ ist. Dann wird sie dauerhaft mit voller Helligkeit
leuchten.
