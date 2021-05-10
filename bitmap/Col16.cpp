#include "Col16.h"

namespace bitFortuna {

	Col16::Col16(BYTE* data, void (*read)(BYTE*, unsigned short*))
	{
		colour = 0;
	
		read(data, &colour);
	}

	/**
	 *  Reads a 16 bit colour form a data stream.
	 *
	 * @param data a pointer to the data stream.
	 * @param colour a pointer to the 16 bit colour.
	 */
	void read16Bit(BYTE* data, unsigned short* colour)
	{
		memcpy(colour, data, 2);
		*colour |= (*colour << 1) & 0x3E000;
	}

	/**
	 *  Reads the raw data from a 24 bit colour
	 * into a 16 bit colour.
	 *
	 * The structure of a 24 bit colour is 8 bits for
	 * red, 8 bits for green and 8 bits for blue.
	 * To convert this into 16 bits, you need to take
	 * the highest value bits of each section.
	 *
	 * @param data a pointer to the 24 bit colour.
	 * @param colour a pointer to the 16 bit colour.
	 */
	void read24BitTo16Bit(BYTE* data, unsigned short* colour)
	{
		for (unsigned short i = 0; i < 5; i++)
			setBit(colour, &data[0], i, i);

		for (unsigned short i = 5; i < 11; i++)
			setBit(colour, &data[1], i - 5, i);

		for (int i = 11; i < 16; i++)
			setBit(colour, &data[2], i - 10, i);
	}

	/**
	 *  Reads the raw data from a 32 bit colour
	 * into a 16 bit colour.
	 *
	 * The structure of a 32 bit colour is 8 bits for
	 * red, 8 bits for green and 8 bits for blue and then
	 * an additional 8 bits for alpha, this can be disregarded.
	 *
	 * @param data a pointer to the 32 bit colour.
	 * @param colour a pointer to the 16 bit colour.
	 */
	void read32BitTo16Bit(BYTE* data, unsigned short* colour)
	{
		read24BitTo16Bit(data, colour);
	}

	void setBit(unsigned short* x, unsigned char* y, unsigned short from, unsigned short too)
	{
		*x |= ((*y >> from) & 1) << too;
	}
}