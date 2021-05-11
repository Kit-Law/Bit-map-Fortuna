#pragma once

#include "Header.h"
#include "Col16.h"
#include "Output.h"

extern "C"
{
	#include "..\fatfs\ff.h"
	#include "..\lcd\lcd.h"
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace bitFortuna {

	/**
	* This function reads the entire pixel array
	* form the bitmap file.
	* 
	* @param file This is a pointer to the file.
	* @param bitmapHeader This is a pointer to the header info
	*					  for the bit map image.
	* @param out This is a pointer to the output function.
	*/
	void readPixelArray(FIL* file, Header* bitmapHeader, void (*out)(unsigned short, int, int));
	/**
	* This function reads a chunk of the pixel array.
	*
	* @param data This is a pointer to the data from the file.
	* @param size This is the size of the chunk in bytes.
	* @param read This is a pointer to the converter function.
	*/
	unsigned short* readPixelChunk(BYTE* data, unsigned short size, void (*read)(BYTE*, unsigned short*));
	/**
	* This function reads a pixel of the pixel array.
	*
	* @param data This is a pointer to the data from the file.
	* @param read This is a pointer to the converter function.
	*/
	unsigned short readPixel(BYTE* data, void (*read)(BYTE*, unsigned short*));

}