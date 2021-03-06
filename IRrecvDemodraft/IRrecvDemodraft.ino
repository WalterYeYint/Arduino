/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;
int ledState=LOW;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value,HEX);
    if(results.value==0xFFA25D)//display 90 on the monitor
    {
      if(ledState==LOW)
      {
        ledState=HIGH;
      }
      else
      {
        ledState=LOW;
      }
      digitalWrite(8,ledState);
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);

}
