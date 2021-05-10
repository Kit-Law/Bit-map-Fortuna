#include "PixelArray.h"
#include <stdlib.h>

namespace bitFortuna {

	void readPixelArray(FIL* file, Header* bitmapHeader, void (*out)(unsigned short, int, int))
	{
		void (*read)(BYTE*, unsigned short*) = NULL;

		if (bitmapHeader->infoHeader.bpp == 16)
			read = read16Bit;
		else if (bitmapHeader->infoHeader.bpp == 24)
			read = read24BitTo16Bit;
		else if (bitmapHeader->infoHeader.bpp == 32)
			read = read32BitTo16Bit;
		else
		{
			display_string("ERROR: invalid bpp.");
			return;
		}

		f_lseek(file, bitmapHeader->paOffset);

		for (int y = 0; y < bitmapHeader->infoHeader.hight; y++)
			for (int x = 0; x < bitmapHeader->infoHeader.width; x++)
			{
				BYTE buffer[2];
				UINT br;

				if (f_read(file, buffer, 2, &br) != FR_OK || br != 2)
				{
					display_string("ERROR: reading pa.");
					return;
				}

				out(readPixel(buffer, read), x, y);
			}

		/*for (int y = 0; y < bitmapHeader->infoHeader.hight; y++)
		{
			unsigned short bufferSize = bitmapHeader->infoHeader.width * (bitmapHeader->infoHeader.bpp / 8);
			BYTE* buffer = (BYTE*)malloc(bufferSize);
			UINT br;

			if (f_read(file, buffer, bufferSize, &br) != FR_OK || br != bufferSize)
			{
				display_string("ERROR: reading pa.");
				return;
			}

			unsigned short* paBuf = readPixelChunk(buffer, bufferSize, read);

			for (unsigned short j = 0; j < bitmapHeader->infoHeader.width; j++)
				out(paBuf[j], j, y);

			free(paBuf);
			free(buffer);
		}*/
	}

	unsigned short* readPixelChunk(BYTE* data, unsigned short size, void (*read)(BYTE*, unsigned short*))
	{
		unsigned short* pa = (unsigned short*)malloc(size);

		for (int i = 0; i < size / 2; i++)
			pa[i] = readPixel(&data[i], read);

		return pa;
	}

	unsigned short readPixel(BYTE* data, void (*read)(BYTE*, unsigned short*))
	{
		return Col16(data, read).colour;
	}

}