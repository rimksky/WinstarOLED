#include <WinstarOLED.h>
#include <LiquidCrystal.h>

WinstarOLED lcd;

void setup() {
  lcd.reset();
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() 
{
  // Set the cursor to column 0, line 0
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  
  // Set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  lcd.print("Uptime: ");
  lcd.print(millis()/1000);
  lcd.print("s");
 }
