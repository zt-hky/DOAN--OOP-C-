#pragma once

// Output Console Color

#include <stdio.h>
#include <Windows.h>
#include <string>

class COCC
{
protected:
	COORD m_Coord;
	WORD m_Color;
	static HANDLE SSHO;  // Static Standard Handle Output
	static DWORD dummy;
public:

	static void gotoXY(const SHORT& _X, const SHORT& _Y);
	static void gotoXY(const COORD& _coord);
	static void setColor(const WORD _color);
	static void setColor(WORD _colorFont, WORD _colorBack);
	static void Fill(const unsigned char& _char,const int& n,const COORD& _coord,WORD _color);
	static void FillA(const WORD& _color, const int& n, const COORD& _coord);
	static void FillC(const unsigned char& _char, const int& n, const COORD& _coord);
	static void OutStr(const char* _str, COORD _coord, WORD _color);
	static void OutStrC(const char* _str, COORD _coord);
	static void OutString(std::string _str, COORD _coord, WORD _color);
	static void OutStringC(std::string _str, COORD _coord);
	static void FillAString(char* _str, COORD& _coord, WORD _color);
	static void OutInt(int _int, COORD _coord, WORD _color);
	static void OutInt(int _int, COORD _coord);
	static void Border(COORD _coord, WORD _color , SHORT _W, SHORT _L);
	static void BorderFillBackground(COORD _coord, WORD _color, SHORT _W, SHORT _L);
	void gotoXY();
	void setColor();
	COCC();
	~COCC();
};

