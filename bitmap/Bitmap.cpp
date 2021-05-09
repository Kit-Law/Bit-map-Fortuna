#include "Bitmap.h"

namespace bitFortuna {

	Bitmap::Bitmap(const char* filename)
	{
		f_mount(&fatFs, "", 0);

		if (f_open(&file, filename, FA_READ) != FR_OK)
			return;

		readHeader(&file, &header);

		//readPA(&file, &header);

		//Cleanup
		f_close(&file);
	}

	void Bitmap::display_debug()
	{
		char buffer[100];

		sprintf(buffer, "Size: %lu \n", header.size);
		display_string(buffer);
		sprintf(buffer, "Pixel Array Offset: %lu \n", header.paOffset);
		display_string(buffer);
		sprintf(buffer, "Width: %lu \n", header.infoHeader.width);
		display_string(buffer);
		sprintf(buffer, "Hight: %lu \n", header.infoHeader.hight);
		display_string(buffer);
		sprintf(buffer, "Planes: %hu \n", header.infoHeader.planes);
		display_string(buffer);
		sprintf(buffer, "Bits Per Pixel: %hu \n", header.infoHeader.bpp);
		display_string(buffer);
		sprintf(buffer, "Compression: %lu \n", header.infoHeader.compression);
		display_string(buffer);
		sprintf(buffer, "X Pixels Per M: %lu \n", header.infoHeader.XpixelsPerM);
		display_string(buffer);
		sprintf(buffer, "Y Pixels Per M: %lu \n", header.infoHeader.YpixelsPerM);
		display_string(buffer);
		sprintf(buffer, "Colours Used: %lu \n", header.infoHeader.colsUsed);
		display_string(buffer);
		sprintf(buffer, "Colours Used: %lu \n", header.infoHeader.colsImport);
		display_string(buffer);
	}

	void readHeader(FIL* file, Header* header)
	{
		BYTE buffer[14];
		UINT br;

		if (f_read(file, buffer, 14, &br) != FR_OK || br != 14)
			return;

		memcpy(&header->size, &buffer[2], 4);
		memcpy(&header->paOffset, &buffer[10], 4);

		readInfoHeader(file, header);
	}

	void readInfoHeader(FIL* file, Header* header)
	{
		BYTE buffer[40];
		UINT br;

		if (f_read(file, buffer, 40, &br) != FR_OK || br != 40)
			return;

		//memcpy(&header->infoHeader., &buffer[0], 4); //TODO: This needs to be read first and determine the size of the bitmap
		memcpy(&header->infoHeader.width,       &buffer[4],  4);
		memcpy(&header->infoHeader.hight,       &buffer[8],  4);
		memcpy(&header->infoHeader.planes,      &buffer[12], 2);
		memcpy(&header->infoHeader.bpp,         &buffer[14], 2);
		memcpy(&header->infoHeader.compression, &buffer[16], 4);
		memcpy(&header->infoHeader.imageSize,   &buffer[20], 4);
		memcpy(&header->infoHeader.XpixelsPerM, &buffer[24], 4);
		memcpy(&header->infoHeader.YpixelsPerM, &buffer[28], 4);
		memcpy(&header->infoHeader.colsUsed,    &buffer[32], 4);
		memcpy(&header->infoHeader.colsImport,  &buffer[36], 4);
	}

	void readPA(FIL* file, Header* header)
	{
		f_lseek(file, header->paOffset);

		char buffer[200];
		UINT br;

		f_read(file, buffer, 200, &br);

		display_string(buffer);
	}

}