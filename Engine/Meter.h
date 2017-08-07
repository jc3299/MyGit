#pragma once

#include "Graphics.h"

class Meter
{
public:
	Meter( int x,int y )
		:
		x( x ),
		y( y )
	{}
	void IncreaseLevel()
	{
		++level;
	}
	int GetLevel() const
	{
		return level;
	}
	void Draw( Graphics& gfx ) const
	{
		gfx.DrawRectDim( x,y,level * scale,girth,c );
	}
private:
	const Color c = Colors::Blue;
	const int girth = 12;
	const int scale = 4;
	int level = 0;
	int x;
	int y;
};
