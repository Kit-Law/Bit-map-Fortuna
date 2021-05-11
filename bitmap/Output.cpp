#include "Output.h"

namespace bitFortuna {

	void beginOutput(Header* header)
	{
		write_cmd(COLUMN_ADDRESS_SET);
		write_data16(0);
		write_data16(header->infoHeader.width - 1);
		write_cmd(PAGE_ADDRESS_SET);
		write_data16(0);
		write_data16(header->infoHeader.hight - 1);
		write_cmd(MEMORY_WRITE);
	}

	void outputPixel(unsigned short colour, int x, int y)
	{
		write_data16(colour);
	}

}