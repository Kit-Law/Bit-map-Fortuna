#pragma once

#include "Header.h"

extern "C"
{
	#include "..\lcd\lcd.h"
	#include "..\lcd\ili934x.h"
}

namespace bitFortuna {

	/**
	* This function initalizes the section of data for
	* the pixels on the screen.
	*/
	void beginOutput(Header* header);
	/**
	* This function can be overridern to be able to
	* display onto other micro controllers.
	* 
	* @param colour This is the colour of the pixel in 16 bits.
	* @param x This is the point on the x axix.
	* @param y This is the point on the y axix.
	*/
	void outputPixel(unsigned short colour, int x, int y);

}