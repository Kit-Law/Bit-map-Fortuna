#pragma once

#include "Header.h"

extern "C"
{
	#include "..\fatfs\ff.h"
	#include "..\lcd\lcd.h"
	#include <stdio.h>
}

#include <string.h>

namespace bitFortuna {

	class Bitmap
	{
	private:
		FATFS fatFs;
		FIL file;
		Header header;
	public:
		Bitmap(const char* filename);

		void display_debug();

		Header* getHeader() { return &header; }
		FIL* getFile() { return &file; }
	};

	void readHeader(FIL* file, Header* header);
	void readInfoHeader(FIL* file, Header* header);
	
	void readPA(FIL* file, Header* header);
}

