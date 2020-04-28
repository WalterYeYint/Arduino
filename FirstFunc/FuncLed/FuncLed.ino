#include <FirstFled.h>

LedFirst ffl(13);

void setup()
{
}

void loop()
{
	ffl.Light(13);
	ffl.FledDelay(4000);
	ffl.LightDown(13);
	ffl.FledDelay(4000);
}
