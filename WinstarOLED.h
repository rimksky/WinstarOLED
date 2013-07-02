#ifndef WinstarOLED_h
#define WinstarOLED_h

#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "LiquidCrystal.h"

// commands
#define LCD_SETGRAPHICMODE 0x1f
#define LCD_SETCHARCTERMODE 0x17

class WinstarOLED : public LiquidCrystal {
public:
  WinstarOLED(uint8_t rs, uint8_t enable, uint8_t pw, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) :
  LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7){ _pw_pin = pw; _is_graphicmode = 0; }
  WinstarOLED(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t pw, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) :
  LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7){ _pw_pin = pw; _is_graphicmode = 0; }
  WinstarOLED(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t pw, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) :
  LiquidCrystal(rs, rw, enable, d0, d1, d2, d3){ _pw_pin = pw; _is_graphicmode = 0; }
  WinstarOLED(uint8_t rs, uint8_t enable, uint8_t pw, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) :
  LiquidCrystal(rs, enable, d0, d1, d2, d3){ _pw_pin = pw; _is_graphicmode = 0; }
  WinstarOLED() :  LiquidCrystal(10, 11, 12, 8, 7, 6, 5){ _pw_pin = 9; _is_graphicmode = 0; }

  void setGraphicMode();
  void setCharcterMode();
  void setGraphicCursor( uint8_t x, uint8_t y );
  void reset();
private:
  uint8_t _pw_pin;
  uint8_t _is_graphicmode;
};

#endif
