#pragma once

#include "Header.h"
#include "Col16.h"

#include <stdlib.h>

extern "C"
{
	#include "..\fatfs\ff.h"
	#include "..\lcd\lcd.h"
	#include <stdio.h>
}

#define CHUNK_SIZE 10

namespace bitFortuna {

	void readPixelArray(FIL* file, Header* bitmapHeader, unsigned short chunkSize, void (*out)(BIT*, unsigned short*));
	Col16* readPixelChunk(BIT* data, unsigned short size, unsigned short bpp, void (*read)(BIT*, BIT*));
	Col16 readPixel(BIT* data, void (*read)(BIT*, BIT*));

}