#pragma once

/* SVG Color Names mapped to 16bit RGB
   with 5-6-5 bit allocation:

	  | Red   | Green | Blue  |
	  |-------+-------+-------|
	  | 5 bit | 6 bit | 5 bit |
	  |-------+-------+-------|
*/

#include <string.h>

typedef bool BIT;

namespace bitFortuna {

	struct Col16
	{
		BIT colour[16];

		Col16(void* data, void (*read)(BIT*, BIT*));
	};

	void read16Bit(BIT* data, BIT* colour);
	void read24BitTo16Bit(BIT* data, BIT* colour);
	void read32BitTo16Bit(BIT* data, BIT* colour);

}