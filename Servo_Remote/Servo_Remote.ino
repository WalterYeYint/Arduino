/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
#include <Servo.h>

Servo ab;

int RECV_PIN = 11;
int x=90;
int ledState=LOW;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  ab.attach(8);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value,HEX);
    if(results.value==0xFFB04F)//display 90 on the monitor
    {
      while(results.value!=0xFFE21D)
      {
        ab.write(x);
        delay(15);
        if(x>=180)
        {
          break;
        }
        x++;
        if (irrecv.decode(&results)) 
        {
          Serial.println(results.value,HEX);
        }
      }
    }
    
    if(results.value==0xFF9867)//display 90 on the monitor
    {
      while(results.value!=0xFFE21D)
      {
        ab.write(x);
        delay(15);
        if(x<=0)
        {
          break;
        }
        x--;
        if (irrecv.decode(&results)) 
        {
          Serial.println(results.value,HEX);
        }
      }
    }
    
    irrecv.resume(); // Receive the next value
  }
}
