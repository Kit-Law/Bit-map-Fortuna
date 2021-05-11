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

	void readPixelArray(FIL* file, Header* bitmapHeader, void (*out)(unsigned short, int, int));
	unsigned short* readPixelChunk(BYTE* data, unsigned short size, void (*read)(BYTE*, unsigned short*));
	unsigned short readPixel(BYTE* data, void (*read)(BYTE*, unsigned short*));

}