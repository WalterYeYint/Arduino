int enA=10;
int in1=9;
int in2=8;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
}

void demoOne()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enA,200);
  delay(2000);

  digitalWrite(in2,LOW);
  digitalWrite(in1,LOW);
  delay(2000);

  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  delay(2000);

  digitalWrite(in2,LOW);
  digitalWrite(in1,LOW);
}

void demoTwo()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  for(int i=0;i<226;i++)
  {
    analogWrite(enA,i);
    delay(200);
  }

  for(int i=255;i>=0;--i)
  {
    analogWrite(enA,i);
    delay(200);

  }
  digitalWrite(in2,LOW);
  digitalWrite(in1,LOW);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  demoOne();
  delay(1000);
  demoTwo();
  delay(1000);
}
