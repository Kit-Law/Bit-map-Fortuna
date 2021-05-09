#pragma once

#include <string.h>

typedef bool BIT;

namespace bitFortuna {

	struct Col16
	{
		BIT colour[16];

		Col16(BIT* data, void (*read)(BIT*, BIT*));
	};

	void read16Bit(BIT* data, BIT* colour);
	void read24BitTo16Bit(BIT* data, BIT* colour);
	void read32BitTo16Bit(BIT* data, BIT* colour);

}