#pragma once

#include "Header.h"

extern "C"
{
	#include "..\lcd\lcd.h"
	#include "..\lcd\ili934x.h"
}

namespace bitFortuna {

	void beginOutput(Header* header);
	void outputPixel(unsigned short colour, int x, int y);

}