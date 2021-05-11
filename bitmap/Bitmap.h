#pragma once

#include "Header.h"
#include "PixelArray.h"
#include "Output.h"

extern "C"
{
	#include "..\fatfs\ff.h"
	#include "..\lcd\lcd.h"
	#include <stdio.h>
	#include <stdlib.h>
}

#include <string.h>

namespace bitFortuna {

	/**
	* This class holds all of the data for a bitmap and
	* also just displays the image to the screen.
	*/
	class Bitmap
	{
	private:
		FIL file;
		Header header;
	public:
		/* This constructor reads the bitmap image header and
		And the pixel array and displays it to the screen. */
		Bitmap(const char* filename);

		/* This method displays the header info to the screen. */
		void display_debug();

		/* This returns the header for the bitmap. */
		Header* getHeader() { return &header; }
		FIL* getFile() { return &file; }
	};

	void readHeader(FIL* file, Header* header);
	void readInfoHeader(FIL* file, Header* header);
}

