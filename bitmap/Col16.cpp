#include "Col16.h"

namespace bitFortuna {

	Col16::Col16(BIT* data, void (*read)(BIT*, BIT*))
	{
		read(data, colour);
	}

	/**
	 *  Reads a 16 bit colour form a data stream.
	 *
	 * @param data a pointer to the data stream.
	 * @param colour a pointer to the 16 bit colour.
	 */
	void read16Bit(BIT* data, BIT* colour)
	{
		memcpy(data, colour, 2);
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
	void read24BitTo16Bit(BIT* data, BIT* colour)
	{
		for (int i = 0; i < 5; i++)
			colour[i] = data[i];

		for (int i = 5; i < 10; i++)
			colour[i] = data[i + 3];

		for (int i = 10; i < 15; i++)
			colour[i] = data[i + 6];

		colour[15] = 0;
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
	void read32BitTo16Bit(BIT* data, BIT* colour)
	{
		read24BitTo16Bit(data, colour);

		colour[15] = data[24];
	}

}