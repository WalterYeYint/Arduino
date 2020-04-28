//this is a header file

#ifndef Blinker_h
#define Blinker_h
#include "Arduino.h"

class Blinker
{
	public:
		Blinker(int pinA, int pinB, int pinC);
		void blinkSingle();
		void blinkDouble();
		void blinkTriple();

	private:
		int _pinA;
		int _pinB;
		int _pinC;
};

#endif