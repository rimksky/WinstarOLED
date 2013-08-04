WinstarOLED for Arduino IDE
===========
For Winstar Charactor OLED (G/C Mode)

_by rimksky@gmail.com 2013-07-03_

Tested Devices
--------------
* WEH000802A (Charactor 8x2 OLED)
* [WEH001602A](http://www.adafruit.com/datasheets/WEH1602.pdf) (Charactor 16x2 OLED)
* WEG010016A (Graphic 100x16 OLED) * Probably Bypass capacitor(ceramic over 0.2microF) is required.

Note
----
This Class is a overwrited LiquidCrystal (Arduino IDE 1.05) Class.
Don't forget `#include "LiquidCrystal.h"` on your sketch.

Constructor Functions differ compared with `LiquidCrystal.h`. (add `pw_pin` number)

Sample Circuit
---------------
The original LiquidCrystal library doesn't correctly initialize or reset Winstar OLED devices,
so this circuit controls the OLED power via a [MOSFET-N](https://en.wikipedia.org/wiki/2N7000).
The following sample circuit shows the default pins for the library.

```
  arduino                           OLED
  Vcc ------------------------------ Vcc
               MOSFET-N (d) -------- GND
  GND -------- MOSFET-N (s)
  D9  -------- MOSFET-N (g)
  D10 ------------------------------ RS
  D11 ------------------------------ RW
  D12 ------------------------------ EN
  D5 ------------------------------- DB7
  D6-------------------------------- DB6
  D7-------------------------------- DB5
  D8 ------------------------------- DB4
```

![](blob/master/examples/HelloWorld/HelloWorld.jpg?raw=true)