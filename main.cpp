#include "bitmap/Bitmap.h"

extern "C"
{
	#include ".\lcd\lcd.h"
}

int main(void)
{
	 /* 8MHz clock, no prescaling (DS, p. 48) */
	CLKPR = (1 << CLKPCE);
	CLKPR = 0;

	DDRB |= _BV(PB7);  	 /* LED as output */

	init_lcd();

	bitFortuna::Bitmap bm("pepe.BMP");

	for (;;) {}

	return 0;
}