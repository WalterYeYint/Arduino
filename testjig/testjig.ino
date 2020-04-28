#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
void setup() 
{
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Hello,World!");
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("            ");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  x=analogRead(A0);
  y=
  if(x<
  lcd.setCursor(1,0);
  lcd.print(millis()/1000);
}
