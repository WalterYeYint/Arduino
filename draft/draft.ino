#define outputA 8
#define outputB 9

int counter=0;
int aState;
int aLastState;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(outputA,INPUT);
  pinMode(outputB,INPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  aState=digitalRead(outputA);
  if(aState==1)
  {
    Serial.print("____");
    Serial.println(aState);
  }
  else
  {
    Serial.println(aState);
  }
    
  delay(50);
}
