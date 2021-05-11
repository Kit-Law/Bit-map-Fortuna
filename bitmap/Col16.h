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

	/* This class reads a BYTE array and returns a 16bit colour */
	struct Col16
	{
		unsigned short colour;

		Col16(BYTE* data, void (*read)(BYTE*, unsigned short*));
	};

	/**
	 *  Reads a 16 bit colour form a data stream.
	 *
	 * @param data a pointer to the data stream.
	 * @param colour a pointer to the 16 bit colour.
	 */
	void read16Bit(BYTE* data, unsigned short* colour);
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
	void read24BitTo16Bit(BYTE* data, unsigned short* colour);
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
	void read32BitTo16Bit(BYTE* data, unsigned short* colour);

	/** This function sets the bit values of x
	 *
	 * @param x a pointer to the value to change.
	 * @param y a pointer tot he source.
	 * @param from the index of the bit form y.
	 * @param too the index of the bit form x.
	 */
	void setBit(unsigned short* x, unsigned char* y, unsigned short from, unsigned short too);

}