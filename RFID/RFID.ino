#include <SPI.h>
#include <MFRC522.h>

const int pinRST=9;
const int pinSDA=10;
char data[9]={"66CC888D"};
char ch[9];
int i=0, j=0;

MFRC522 mfrc522(pinSDA,pinRST);
void setup() 
{
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() 
{
  if(mfrc522.PICC_IsNewCardPresent())
  {
    if(mfrc522.PICC_ReadCardSerial())
    {
      for(byte i=0; i<mfrc522.uid.size; i++)
      {
        Serial.print(mfrc522.uid.uidByte[i],HEX);
        ch[i]=(mfrc522.uid.uidByte[i],HEX);

        if(ch[i]==data[i])
        {
          j++;
        }

        if(j==8)
        {
          Serial.println("True");
          j=0;
        }
      }
      Serial.println();
      Serial.println(ch[3]);
      Serial.println();
  // put your main code here, to run repeatedly:
    }
    
  }
}
