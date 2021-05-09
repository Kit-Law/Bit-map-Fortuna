#pragma once

namespace bitFortuna {

	struct Header
	{
		unsigned long size;
		unsigned long paOffset;

		struct InfoHeader
		{
			unsigned long width;
			unsigned long hight;

			unsigned short planes;
			unsigned short bpp;
			unsigned long compression;
			unsigned long imageSize;

			unsigned long XpixelsPerM;
			unsigned long YpixelsPerM;

			unsigned long colsUsed;
			unsigned long colsImport;
		} infoHeader;
	};

}
