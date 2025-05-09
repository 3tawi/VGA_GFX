/*
	Author: bitluni 2019
	License: 
	Creative Commons Attribution ShareAlike 4.0
	https://creativecommons.org/licenses/by-sa/4.0/
	
	For further details check out: 
		https://youtube.com/bitlunislab
		https://github.com/bitluni
		http://bitluni.net
*/
#pragma once

template<class Base>
class VGAWrapper : public GP_GFX
{
  public:
	Base &base;
	typedef typename Base::Color Color;
	VGAWrapper(Base &vga, const int xres, const int yres)
		:base(vga),
		GP_GFX(xres, yres)
	{
	}

	virtual void drawPixel(int16_t x, int16_t y, uint16_t color)
	{
		base.dotFast(x, y, base.RGBA((color >> 8) & 0b11111000, (color >> 3) & 0b11111100, (color << 3) & 0b11111000));
	}
};