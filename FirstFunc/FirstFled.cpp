#include "FirstFled.h"

LedFirst::LedFirst(int pin1)
{
	pinMode(pin1,OUTPUT);
}

void LedFirst::Light(int pin2)
{
	digitalWrite(pin2,HIGH);
}

void LedFirst::FledDelay(int del)
{
	delay(del);
}

void LedFirst::LightDown(int pin3)
{
	digitalWrite(pin3,LOW);
}