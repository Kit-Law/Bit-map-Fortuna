#include "PixelArray.h"

namespace bitFortuna {

	void readPixelArray(FIL* file, Header* bitmapHeader, void (*out)(Col16*, unsigned short))
	{
		void (*read)(BIT*, BIT*);

		if (bitmapHeader->infoHeader.bpp == 16)
			read = read16Bit;
		else if (bitmapHeader->infoHeader.bpp == 24)
			read = read24BitTo16Bit;
		else if (bitmapHeader->infoHeader.bpp == 32)
			read = read32BitTo16Bit;

		for (int i = 0; i < bitmapHeader->infoHeader.imageSize; i += CHUNK_SIZE)
		{
			BIT buffer[CHUNK_SIZE * 8];
			UINT br;

			if (f_read(file, buffer, CHUNK_SIZE * 8, &br) != FR_OK || br != CHUNK_SIZE * 8)
				return;

			Col16* paBuf = readPixelChunk(buffer, CHUNK_SIZE, bitmapHeader->infoHeader.bpp, read);

			out(paBuf, CHUNK_SIZE);

			free(paBuf);
		}
	}

	Col16* readPixelChunk(BIT* data, unsigned short size, unsigned short bpp, void (*read)(BIT*, BIT*))
	{
		Col16* chunk;
		chunk = (Col16*) malloc(sizeof(Col16) * size);

		for (int i = 0; i < size; i++)
			chunk[i] = readPixel(&data[bpp * i - i], read);

		return chunk;
	}

	Col16 readPixel(BIT* data, void (*read)(BIT*, BIT*))
	{
		return Col16(data, read);
	}

}