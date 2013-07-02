WinstarOLED
===========

WinstarOLED for arduino IDE

 WinstarOLED
  Arduino Library for Winstar Charactor OLED (G/C Mode)
  by rimksky@gmail.com 2013-07-03

 Tested Devices:
   WEH000802A (Charactor 8x2 OLED)
   WEH001602A (Charactor 16x2 OLED)
   WEG010016A (Graphic 100x16 OLED) * Probably Bypass capacitor(ceramic over 0.2microF) is required.

 Note:
 This Class is a overwrited LiquidCrystal (Arduino IDE 1.05) Class.
 Don't forget #include "LiquidCrystal.h" on your sketch.

 Constructor Functions differ compared with LiquidCrystal.h. (add pw_pin number)

 Circuit of OLED devices:
 Original LiquidCrystal can't initialize Winstar OLED devices correctly. (and reset too) 
 So, It make correct initializing that arduino pin connect to OLED power pin via MOSFET-N.
 The sample circuit is as follows. ( and, this is defualt pin number of this library. )

  arduino                           OLED
  Vcc ------------------------------ Vcc
               MOSFET-N (s) -------- GND
  GND -------- MOSFET-N (d)
  D9  -------- MOSFET-N (g)
  D10 ------------------------------ RS
  D11 ------------------------------ EN
  D12 ------------------------------ RW
  D5 ------------------------------- DB7
  D6-------------------------------- DB6
  D7-------------------------------- DB5
  D8 ------------------------------- DB4
