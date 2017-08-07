/******************************************************************************************
*	Chili DirectX Framework Version 16.07.20											  *
*	Colors.h																			  *
*	Copyright 2016 PlanetChili <http://www.planetchili.net>								  *
*																						  *
*	This file is part of The Chili DirectX Framework.									  *
*																						  *
*	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#pragma once

class Color
{
public:
	unsigned int dword;
public:
	const Color() : dword() {}
	const Color( const Color& col )
		:
		dword( col.dword )
	{}
	const Color( unsigned int dw )
		:
		dword( dw )
	{}
	const Color( unsigned char x,unsigned char r,unsigned char g,unsigned char b )
		:
		dword( (x << 24u) | (r << 16u) | (g << 8u) | b )
	{}
	const Color( unsigned char r,unsigned char g,unsigned char b )
		:
		dword( (r << 16u) | (g << 8u) | b )
	{}
	const Color( Color col,unsigned char x )
		:
		Color( (x << 24u) | col.dword )
	{}
	Color& operator =( Color color )
	{
		dword = color.dword;
		return *this;
	}
	const unsigned char GetX() const
	{
		return dword >> 24u;
	}
	const unsigned char GetA() const
	{
		return GetX();
	}
	const unsigned char GetR() const
	{
		return (dword >> 16u) & 0xFFu;
	}
	const unsigned char GetG() const
	{
		return (dword >> 8u) & 0xFFu;
	}
	const unsigned char GetB() const
	{
		return dword & 0xFFu;
	}
	void SetX( unsigned char x )
	{
		dword = (dword & 0xFFFFFFu) | (x << 24u);
	}
	void SetA( unsigned char a )
	{
		SetX( a );
	}
	void SetR( unsigned char r )
	{
		dword = (dword & 0xFF00FFFFu) | (r << 16u);
	}
	void SetG( unsigned char g )
	{
		dword = (dword & 0xFFFF00FFu) | (g << 8u);
	}
	void SetB( unsigned char b )
	{
		dword = (dword & 0xFFFFFF00u) | b;
	}
};

namespace Colors
{
	static const Color MakeRGB( unsigned char r,unsigned char g,unsigned char b )
	{
		return (r << 16) | (g << 8) | b;
	}
	static const Color White = MakeRGB( 255u,255u,255u );
	static const Color Black = MakeRGB( 0u,0u,0u );
	static const Color Gray = MakeRGB( 0x80u,0x80u,0x80u );
	static const Color LightGray = MakeRGB( 0xD3u,0xD3u,0xD3u );
	static const Color Red = MakeRGB( 255u,0u,0u );
	static const Color Green = MakeRGB( 0u,255u,0u );
	static const Color Blue = MakeRGB( 0u,0u,255u );
	static const Color Yellow = MakeRGB( 255u,255u,0u );
	static const Color Cyan = MakeRGB( 0u,255u,255u );
	static const Color Magenta = MakeRGB( 255u,0u,255u );
}