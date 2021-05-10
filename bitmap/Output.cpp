#include "Output.h"

namespace bitFortuna {

	void outputPixel(unsigned short colour, int x, int y)
	{
		rectangle r;

		r.top = y;
		r.bottom = y;
		r.left = x;
		r.right = x;

		fill_rectangle(r, colour);
	}

}