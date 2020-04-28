float no=0;
float x=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  x=analogRead(0);
  no=5*x/1023;
  Serial.println(no);
}
