#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
#define LED_1     13
#define LED_2     12


char inputs   [20];
char oldInputs[20];
char L1=0;
char L2=0;

void setup() {
    Serial.begin(115200);
    lcd.begin(16,2);
}

void loop() {
    
    if(Serial.available()){
        int ind=0;
        char buff[5];
        while(Serial.available()){
            unsigned char c = Serial.read();
            buff[ind] = c;
            ind++;
            if(ind > 4) break;
        }
        
            L1 = 1-L1;
            lcd.setCursor(0,0);
            lcd.print(buff);
        
        if(strcmp(buff, "L2")==0){
            L2 = 1-L2;
            lcd.setCursor(0,0);
            lcd.print(buff);
        }     
    }
    delay(10);
}

