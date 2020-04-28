char ch='0',oldch='1';
char newch='0';
int newnum=0;
char arch[]={'0'};
int arnum[]={'0'};
int x=0,count=1,i=0,j=0,k=0,h=0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    ch=Serial.read();
    if(ch!='R')
    {
      if(ch==oldch)
      {
        count++;
      }
      if(i>1)
      {
        if(ch!=oldch)
        {
          arch[j]=oldch;
          arnum[j]=count;
          oldch=ch;
          count=1;
          Serial.println(arch[j]);
          Serial.println(arnum[j]);
          j++;
        }
      }
      
      
      /*if(ch=='F')
      {
        digitalWrite(8,HIGH);
        delay(500);
        digitalWrite(8,LOW);
      }
      if(ch=='B')
      {
        digitalWrite(10,HIGH);
        delay(500);
        digitalWrite(10,LOW);
      }*/
      i=2;
    }
    /*else
    {
      for(k=j;k>=0;k--)
      {
        newch=arch[k];
        newnum=arnum[k];

        for(h=newnum;h>0;h--)
        {
          Serial.print(newch);
          if(newch=='F')
          {
            digitalWrite(8,HIGH);
            delay(500);
            digitalWrite(8,LOW);
          }
          if(newch=='B')
          {
            digitalWrite(10,HIGH);
            delay(500);
            digitalWrite(10,LOW);
          }
        }
      }
    }*/
  }
}
