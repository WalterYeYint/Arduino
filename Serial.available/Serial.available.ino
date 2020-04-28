int x;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(!Serial.available())
  {
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
  }
  else
  {
    x=Serial.read();
    if(x=='1')
    {
      digitalWrite(8,HIGH);  
      digitalWrite(10,LOW);
      delay(2000);
        
    }
    else
    {
      digitalWrite(10,HIGH);
      digitalWrite(8,LOW);
      delay(2000);
    }
    
  }
}
