#pragma once

/* SVG Color Names mapped to 16bit RGB
   with 5-6-5 bit allocation:

	  | Red   | Green | Blue  |
	  |-------+-------+-------|
	  | 5 bit | 6 bit | 5 bit |
	  |-------+-------+-------|
*/

extern "C"
{
#include "..\fatfs\ff.h"
#include "..\lcd\lcd.h"
#include <stdio.h>
}

#include <string.h>

typedef unsigned char BYTE;

namespace bitFortuna {

	struct Col16
	{
		unsigned short colour;

		Col16(BYTE* data, void (*read)(BYTE*, unsigned short*));
	};

	void read16Bit(BYTE* data, unsigned short* colour);
	void read24BitTo16Bit(BYTE* data, unsigned short* colour);
	void read32BitTo16Bit(BYTE* data, unsigned short* colour);

	void setBit(unsigned short* x, unsigned char* y, unsigned short from, unsigned short too);

}