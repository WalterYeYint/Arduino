#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int n,x;
float y=5.123;
float z=0.000;
unsigned long cur,prev=0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(9,INPUT);
  lcd.begin(16,2);
  lcd.print("Hello,World!");
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("            ");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  n=Serial.read();
  if(n=='1')
  {
    cur=millis()/1000;
    prev=cur;
    while(true)
    {
      lcd.setCursor(0,1);
      unsigned long cur=millis()/1000;
      lcd.print(cur);
      if(cur-prev==10)
      {
        lcd.setCursor(0,0);
        lcd.print("The sensor has passed the test");
      }
      else if(cur-prev==8)
      {
        lcd.setCursor(0,0);
        lcd.print("Test interrupted");
        prev=cur;
        break;
      }
    }
    
  }
  else if(n=='2')
  {
    x=digitalRead(9);
    if(x==LOW)
    {
      lcd.print(z);
    }
    else
    {
      lcd.print(y);
    }
    
  }
  
}
