String data="aim";
int i=0;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    if(Serial.readString()==data)
    {
      i++;
      Serial.println(i);
      if(i==3)
      {
        i=0;
        Serial.println("True");
      }
    }
    else
    {
      i=0;
    }
  }
  
}
