#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int n,x,a;
float b=0.0000;
float c=0.0000;
float z=0.0000;
unsigned long cur,prev=0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  lcd.begin(16,2);
  lcd.print("Hello,World!");
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("            ");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  while(digitalRead(13)==LOW)
  {
    lcd.setCursor(0,0);
    lcd.print("Put the sensor  ");
    lcd.setCursor(0,1);
    lcd.print("       ");
    b=analogRead(0)*5/1023;
    Serial.println(b);
    while(b>3 && digitalRead(13)==LOW)
    {
      checkbulb();
      checkpower();
      b=analogRead(0)*5/1023;
      Serial.println(b);
    }
    //b=analogRead(0)*5/1023;
    if(b<3 && digitalRead(13)==LOW)
    {
      cur=millis()/1000;
      prev=cur;
      while(b<3 && digitalRead(13)==LOW)
      {
        checkbulb();
        checkpower();
        b=analogRead(0)*5/1023;
        Serial.println(b);
        lcd.setCursor(0,1);
        unsigned long cur=millis()/1000;
        lcd.print(cur);

        if(b>3 || digitalRead(13)==HIGH)
        {
          lcd.setCursor(0,0);
          lcd.print("Test interrupted"); 
          delay(2000);
          break;
        }
        
        if(cur-prev==5)
        {
          lcd.setCursor(0,0);
          lcd.print("Passed the test!!");
          delay(2000);
          break;
        }
        /*else if(cur-prev==5)
        {
          lcd.setCursor(0,0);
          lcd.print("Test interrupted");
          delay(2000);
          prev=cur;
          break;
        }*/
      }
    }
    
  }
  lcd.setCursor(0,0);
  lcd.print("                   ");
  lcd.setCursor(0,1);
  lcd.print("                   ");

  while(digitalRead(12)==LOW)
  {
    checkbulb();
    checkpower();
    lcd.setCursor(0,0);
    lcd.print("Voltmeter mode     ");
    b=analogRead(0)*5/1023;
    Serial.println(b);
    lcd.setCursor(0,1);
    lcd.print(b);
    delay(500);
  }
  lcd.setCursor(0,0);
  lcd.print("                   ");
  lcd.setCursor(0,1);
  lcd.print("                   ");

  while(digitalRead(13)==HIGH && digitalRead(12)==HIGH)
  {
    checkbulb();
    checkpower();
    lcd.setCursor(0,0);
    lcd.print("Ammeter mode      ");
    b=analogRead(0)*5/(1023*1420);
    lcd.setCursor(0,1);
    lcd.print(b);
    delay(500);
  }
  lcd.setCursor(0,0);
  lcd.print("                   ");
  lcd.setCursor(0,1);
  lcd.print("                   ");
}

void checkbulb()
{
  b=analogRead(0)*5/1023;
  if(b<3)
  {
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
    //Serial.println("Red On");
  }
  else
  {
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    //Serial.println("Green On");
  }
}
void checkpower()
{
  while(analogRead(1)*5/1023<3)
  {
    lcd.setCursor(0,0);
    lcd.print("Insert power       ");
    lcd.setCursor(0,1);
    lcd.print("                   ");
  }
}

