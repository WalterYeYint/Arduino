int x=0;
int y=0;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  while(x<100)
  {
    if(y==15)
    {
      break;
    }
    y++;
    Serial.println(y);
    delay(1000);
  }
}
