# 2. Es leuchtet

## 2.2 Schaltsymbole

| Schaltsymbol                                                              | Name             | Bezeichner |
| ------------------------------------------------------------------------- | ---------------- | ---------- |
| ![Batterie](../_media/arduino-einfuehrung/schaltsymbole/batterie.png)     | Batterie         | Bat        |
| ![Widerstand](../_media/arduino-einfuehrung/schaltsymbole/widerstand.png) | Widerstand       | R          |
| ![LED](../_media/arduino-einfuehrung/schaltsymbole/led.png)               | LED              | D          |
| ![GND](../_media/arduino-einfuehrung/schaltsymbole/gnd.png)               | GND (-)          |            |
| ![5V](../_media/arduino-einfuehrung/schaltsymbole/5v.png)                 | 5V (+)           |            |
| ![NPN](../_media/arduino-einfuehrung/schaltsymbole/npn-transistor.png)    | NPN - Transistor | T          |
| ![PNP](../_media/arduino-einfuehrung/schaltsymbole/pnp-transistor.png)    | PNP - Transistor | T          |

## 2.3 Widerstandsberechnung

![Widerstandsberechnung](../_media/arduino-einfuehrung/widerstaende/widerstands-berechnung.png)

### 2.3.1 5 - Ringe

$Widerstand = \left ( 1.Ring\ 2.Ring\ 3.Ring \right ) \cdot 4.Ring$

$Toleranz = 5.Ring$

#### Beispiele

1. rot-rot-schwarz-schwarz-braun

   ![rot-rot-schwarz-schwarz-braun](../_media/arduino-einfuehrung/widerstaende/rot-rot-schwarz-schwarz-braun.png)

   $2\ 2\ 2\ \cdot 1 = 220\Omega$

2. braun-schwarz-schwarz-gelb-braun

   ![braun-schwarz-schwarz-gelb-braun](../_media/arduino-einfuehrung/widerstaende/braun-schwarz-schwarz-gelb-braun.png)

   $1\ 0\ 0\ \cdot 10.000 = 1.000.000\Omega = 1M\Omega$

### 2.3.2 4 - Ringe

$Widerstand = \left ( 1.Ring\ 2.Ring \right ) \cdot 3.Ring$

$Toleranz = 4.Ring$

#### Beispiele

1. orange-orange-braun-braun

   ![orange-orange-braun-braun](../_media/arduino-einfuehrung/widerstaende/orange-orange-braun-braun.png)

   $3\ 3\ \cdot 10 = 330\Omega$

2. braun-schwarz-blau-braun

   ![braun-schwarz-blau-braun](../_media/arduino-einfuehrung/widerstaende/braun-schwarz-blau-braun.png)

   $1\ 0\ \cdot 1.000.000 = 10.000.000\Omega = 10M\Omega$
