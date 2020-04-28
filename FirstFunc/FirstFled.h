#ifndef fled
#define fled

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class LedFirst
{
	public:
		LedFirst(int pin1);

		void Light(int pin2=13);
		void LightDown(int pin3=13);
		void FledDelay(int del=1000);
};

#endif