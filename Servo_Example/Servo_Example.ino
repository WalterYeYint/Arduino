#include <Servo.h>
Servo ab;
int val;
void setup() 
{
  // put your setup code here, to run once:
  ab.attach(9);
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
  val=analogRead(0);
  val=map(val,0,1023,0,180);
  ab.write(val);
  delay(15);
}
