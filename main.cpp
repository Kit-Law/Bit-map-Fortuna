#include "bitmap/Bitmap.h"
#include "bitmap/Header.h"

extern "C"
{
	#include "os.h"
}

int main(void)
{
	os_init();

	sei();

	bitFortuna::Bitmap bm("bmp.BMP");
	bm.display_debug();
	bitFortuna::readPA(bm.getFile(), bm.getHeader());

	for (;;) {}

	return 0;
}