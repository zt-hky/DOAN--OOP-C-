#pragma once

#include <Windows.h>
#include <stdio.h>
#include "OCC.h"

using namespace std;


class CPixel:public COCC
{
protected:
	char m_Char;
public:
	CPixel& operator= (const CPixel& _pixel);
	bool operator==(const CPixel& _pixel);
	void out();
	void outIfDiffCharColor(const CPixel &x);
	void setXY(COORD _coord);
	void set(const unsigned char _char, int _x, int _y, const char _colorFont, const char _colorBack);
	void set(const unsigned char _char, int _x, int _y, WORD _color);
	void set(const unsigned char _char, COORD _coord, WORD _color);
	void setChar(const unsigned char& _char);
	void setColor(WORD _color);
	void set(unsigned char  _char, WORD _color);
	CPixel();
	~CPixel();
};

