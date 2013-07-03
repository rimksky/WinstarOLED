#include "WinstarOLED.h"

#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/*
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
*/

void WinstarOLED::setGraphicMode(){
  command(LCD_SETGRAPHICMODE);
  _is_graphicmode = 1;
}

void WinstarOLED::setCharcterMode(){
  command(LCD_SETCHARCTERMODE);
  _is_graphicmode = 0;
}

void WinstarOLED::setGraphicCursor( uint8_t x, uint8_t y ){
  if( _is_graphicmode ){
    if( 0 <= x && x <= 100 ){
      command(LCD_SETDDRAMADDR | x);
    }
    if( 0 <= y && y <= 1 ){
      command(LCD_SETCGRAMADDR | y);
    }
  }
}

void WinstarOLED::reset( unsigned int delaytime ){
  pinMode(_pw_pin, OUTPUT);
  digitalWrite(_pw_pin, LOW);
  delay(delaytime);
  digitalWrite(_pw_pin, HIGH);
  delay(delaytime);
}

/*
void WinstarOLED::sync(){
  wait();
  for( int i = 0; i < 5; i++ ){
    write4bits(0x00);
  }
}

void WinstarOLED::wait() {
  pinMode(_data_pins[3], INPUT);
  int busy = HIGH;
  while (busy) {
    digitalWrite(_rs_pin, LOW);
    digitalWrite(_rw_pin, HIGH);
    pulseEnable();
    busy = digitalRead(_data_pins[3]);
    digitalWrite(_rs_pin, LOW);
    digitalWrite(_rw_pin, HIGH);
    pulseEnable();
  }
  pinMode(_data_pins[3], OUTPUT);
}
*/
