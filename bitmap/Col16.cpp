#include "Col16.h"

namespace bitFortuna {

	Col16::Col16(BYTE* data, void (*read)(BYTE*, unsigned short*))
	{
		colour = 0;
	
		read(data, &colour);
	}

	void read16Bit(BYTE* data, unsigned short* colour)
	{
		memcpy(colour, data, 2);
		*colour |= (*colour << 1) & 0x3E000;
	}

	void read24BitTo16Bit(BYTE* data, unsigned short* colour)
	{
		unsigned short r = 0; r |= data[0] & 0xF8;
		unsigned short g = 0; g |= data[1] & 0xFC;
		unsigned short b = 0; b |= data[2] & 0xF8;

		*colour |= r >> 3;
		*colour |= g << 2;
		*colour |= b << 6;
	}

	void read32BitTo16Bit(BYTE* data, unsigned short* colour)
	{
		read24BitTo16Bit(data, colour);
	}

	void setBit(unsigned short* x, unsigned char* y, unsigned short from, unsigned short too)
	{
		*x |= ((*y >> from) & 1) << too;
	}
}