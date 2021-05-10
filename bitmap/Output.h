#pragma once

extern "C"
{
	#include "..\lcd\lcd.h"
}

namespace bitFortuna {

	void outputPixel(unsigned short colour, int x, int y);

}