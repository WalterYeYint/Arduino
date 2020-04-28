#include <Servo.h>
Servo ab;


void setup() 
{
  // put your setup code here, to run once:
  ab.attach(8);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  for(int p=1;p<=180;p++)
  {
    ab.write(p);
    delay(15);
  }
  for(int p=180;p>=0;p--)
  {
    ab.write(p);
    delay(15);
  }
}
