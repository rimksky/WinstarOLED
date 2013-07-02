#include <WinstarOLED.h>
#include <LiquidCrystal.h>

WinstarOLED lcd;

const byte SX = 100;  // less than 100
const byte SY = 2;    // less than 2
byte displayData[2][SX][SY];
byte bufno = 0;

void setup() {
  pinMode(13, OUTPUT);
  randomSeed(analogRead(0) + analogRead(1));
  lcd.reset();
  lcd.begin(16, 2);
  lcd.setGraphicMode();
  lcd.clear();
  setRandomData();
  applyDisplay();
}

void setRandomData() {
  for (byte x = 0; x < SX; x++) {
    for (byte y = 0; y < SY; y++) {
      displayData[bufno][x][y] = (byte) random(256);
    }
  }
}

void clearData() {
  for (byte x = 0; x < SX; x++) {
    for (byte y = 0; y < SY; y++) {
      displayData[bufno][x][y] = 0;
    }
  }
}

void setPoint(byte x, byte y) {
  byte ax = x % SX;
  byte ay = ( y % ( SY * 8 ) ) / 8;
  byte by = ( y % ( SY * 8 ) ) % 8;
  displayData[bufno][ax][ay] |= (1 << by);
}

byte getPoint(byte bufno, byte x, byte y) {
  byte ax = x % SX;
  byte ay = (y % (SY * 8) ) / 8;
  byte by = (y % (SY * 8) ) % 8;
  return displayData[bufno][ax][ay] & (1 << by);
}

void nextData(){
  for (byte x = 0; x < SX; x++) {
    for (byte y = 0; y < SY*8; y++) {
      if( getCount(x, y) ) setPoint(x, y);
    }
  }
}

void applyDisplay() {
  byte x0 = 0xff;
  byte y0 = 0xff;
  for (byte y = 0; y < SY; y++) {
    for (byte x = 0; x < SX; x++) {
      byte b0 = displayData[(bufno+1)%2][x][y];
      byte b1 = displayData[bufno][x][y];
      if( b0 != b1 ){
        lcd.setGraphicCursor(x, y);
        lcd.write(b1);
        x0 = x;
        y0 = y;
      }
    }
  }
  bufno = (bufno+1)%2;
}

byte getCount(byte x, byte y){
  byte preno = (bufno+1)%2;
  byte c = 0;
  byte ret = 0;
  if( getPoint(preno, x-1+SX, y-1+SY*8) ) c++;
  if( getPoint(preno, x, y-1+SY*8) ) c++;
  if( getPoint(preno, x+1, y-1+SY*8) ) c++;
  if( getPoint(preno, x-1+SX, y) ) c++;
  if( getPoint(preno, x+1, y) ) c++;
  if( getPoint(preno, x-1+SX, y+1) ) c++;
  if( getPoint(preno, x, y+1) ) c++;
  if( getPoint(preno, x+1, y+1) ) c++;
  if( getPoint(preno, x, y ) ){
    if( c == 2 || c == 3 ) ret = 1; 
  }
  else{
    if( c == 3 ) ret = 1; 
  }
  return ret;
}

byte gen = 0;
void loop() {
  gen++;
  digitalWrite(13, (byte) gen % 2 );
  clearData();
  nextData();
  applyDisplay();
}
