#include "OCC.h"

HANDLE COCC::SSHO = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD COCC::dummy = 0x0000;

COCC::COCC()
{
}


COCC::~COCC()
{
}

void COCC::gotoXY(const SHORT & _X, const SHORT & _Y)
{
	SetConsoleCursorPosition(SSHO, { _X,_Y });
}

void COCC::gotoXY(const COORD&  _coord)
{
	SetConsoleCursorPosition(SSHO, _coord);
}

void COCC::setColor(WORD _color)
{
	SetConsoleTextAttribute(SSHO, _color);
}

void COCC::setColor(WORD _colorFont, WORD _colorBack)
{
	_colorFont &= 0x00f;
	_colorBack &= 0x00f;
	_colorBack <<= 4;
	_colorBack |= _colorFont;
	SetConsoleTextAttribute(SSHO, _colorBack);
}

void COCC::Fill(const unsigned char& _char, const int& n, const COORD& _coord, WORD _color)
{
	FillConsoleOutputCharacterA(SSHO, _char, n, _coord, &COCC::dummy);
	FillConsoleOutputAttribute(SSHO, _color, n, _coord, &COCC::dummy);
}

void COCC::FillA(const WORD& _color, const  int& n, const  COORD& _coord)
{
	FillConsoleOutputAttribute(SSHO, _color, n, _coord, &COCC::dummy);
}

void COCC::FillC(const unsigned char& _char, const  int& n, const  COORD& _coord)
{
	FillConsoleOutputCharacterA(SSHO, _char, n, _coord, &COCC::dummy);
}

void COCC::OutStr(const char * _str, COORD  _coord, WORD _color)
{
	int lenght = strlen(_str);
	SHORT x = _coord.X;
	SHORT y = _coord.Y;
	FillConsoleOutputAttribute(SSHO, _color, lenght, _coord, &COCC::dummy);
	for (int i = 0; i < lenght; i++)
	{
		FillConsoleOutputCharacterA(SSHO, _str[i], 1, { x,y }, &COCC::dummy);
		x++;
	}
}

void COCC::OutStrC(const char * _str, COORD  _coord)
{
	int lenght = strlen(_str);
	SHORT x = _coord.X;
	SHORT y = _coord.Y;
	for (int i = 0; i < lenght; i++)
	{
		FillConsoleOutputCharacterA(SSHO, _str[i], 1, { x,y }, &COCC::dummy);
		x++;
	}
}

void COCC::OutString(std::string _str, COORD  _coord, WORD _color)
{
	int lenght = _str.length();
	SHORT x = _coord.X;
	SHORT y = _coord.Y;
	FillConsoleOutputAttribute(SSHO, _color, lenght, _coord, &COCC::dummy);
	for (int i = 0; i < lenght; i++)
	{
		FillConsoleOutputCharacterA(SSHO, _str[i], 1, { x,y }, &COCC::dummy);
		x++;
	}
}

void COCC::OutStringC(std::string _str, COORD _coord)
{
	int lenght = _str.length();
	SHORT x = _coord.X;
	SHORT y = _coord.Y;
	for (int i = 0; i < lenght; i++)
	{
		FillConsoleOutputCharacterA(SSHO, _str[i], 1, { x,y }, &COCC::dummy);
		x++;
	}
}

void COCC::FillAString(char * _str, COORD & _coord, WORD _color)
{
	int lenght = strlen(_str);
	FillConsoleOutputAttribute(SSHO, _color, lenght, _coord, &COCC::dummy);
}

void COCC::OutInt(int _int, COORD _coord, WORD  _color)
{
	int n = 0, s;
	SHORT x = _coord.X;
	SHORT y = _coord.Y;
	while (_int != 0)
	{
		s = _int % 10;
		_int /= 10;
		x--;
		FillConsoleOutputCharacterA(SSHO, s + 48, 1, { x,y }, &COCC::dummy);

		n++;
	}
	FillConsoleOutputAttribute(SSHO, _color, n, { x,y }, &COCC::dummy);
}

void COCC::OutInt(int _int, COORD _coord)
{
	int  s;
	SHORT x = _coord.X;
	SHORT y = _coord.Y;
	while (_int != 0)
	{
		s = _int % 10;
		_int /= 10;
		FillConsoleOutputCharacterA(SSHO, s + 48, 1, { x,y }, &COCC::dummy);
		x--;
	}
}

void COCC::Border(COORD _coord, WORD _color, SHORT _W, SHORT _L)
{
	SHORT x = _coord.X, y = _coord.Y;

	FillConsoleOutputAttribute(COCC::SSHO, _color, _W, _coord, &COCC::dummy);
	FillConsoleOutputAttribute(COCC::SSHO, _color, _W, { x ,y + _L -1}, &COCC::dummy);

	FillConsoleOutputCharacterA(COCC::SSHO, 201, 1, _coord, &COCC::dummy);
	FillConsoleOutputCharacterA(COCC::SSHO, 200, 1, { x,y + _L -1}, &COCC::dummy);
	FillConsoleOutputCharacterA(COCC::SSHO, 187, 1, { x + _W-1,y }, &COCC::dummy);
	FillConsoleOutputCharacterA(COCC::SSHO, 188, 1, { x + _W-1,y + _L-1 }, &COCC::dummy);

	FillConsoleOutputCharacterA(COCC::SSHO, 205, _W-2, { x+1,y}, &COCC::dummy);
	FillConsoleOutputCharacterA(COCC::SSHO, 205, _W - 2, { x + 1,y+_L -1}, &COCC::dummy);

	for (SHORT i = 1; i < _L - 1; i++)
	{
		FillConsoleOutputCharacterA(COCC::SSHO, 186, 1, { x ,y +i}, &COCC::dummy);
		FillConsoleOutputCharacterA(COCC::SSHO, 186, 1, { x + _W-1,y +i }, &COCC::dummy);

		FillConsoleOutputAttribute(COCC::SSHO, _color,1, { x ,y + i }, &COCC::dummy);
		FillConsoleOutputAttribute(COCC::SSHO, _color,1, { x + _W - 1,y + i }, &COCC::dummy);

	}
}

void COCC::BorderFillBackground(COORD _coord, WORD _color, SHORT _W, SHORT _L)
{
	SHORT x = _coord.X, y = _coord.Y;

	FillConsoleOutputAttribute(COCC::SSHO, _color, _W, _coord, &COCC::dummy);
	FillConsoleOutputAttribute(COCC::SSHO, _color, _W, { x ,y + _L - 1 }, &COCC::dummy);

	FillConsoleOutputCharacterA(COCC::SSHO, 201, 1, _coord, &COCC::dummy);
	FillConsoleOutputCharacterA(COCC::SSHO, 200, 1, { x,y + _L - 1 }, &COCC::dummy);
	FillConsoleOutputCharacterA(COCC::SSHO, 187, 1, { x + _W - 1,y }, &COCC::dummy);
	FillConsoleOutputCharacterA(COCC::SSHO, 188, 1, { x + _W - 1,y + _L - 1 }, &COCC::dummy);

	FillConsoleOutputCharacterA(COCC::SSHO, 205, _W - 2, { x + 1,y }, &COCC::dummy);
	FillConsoleOutputCharacterA(COCC::SSHO, 205, _W - 2, { x + 1,y + _L - 1 }, &COCC::dummy);

	for (SHORT i = 1; i < _L - 1; i++)
	{
		FillConsoleOutputCharacterA(COCC::SSHO, ' ', _W, { x,y + i }, &COCC::dummy);
		FillConsoleOutputCharacterA(COCC::SSHO, 186, 1, { x ,y + i }, &COCC::dummy);
		FillConsoleOutputCharacterA(COCC::SSHO, 186, 1, { x + _W - 1,y + i }, &COCC::dummy);

		FillConsoleOutputAttribute(COCC::SSHO, _color, _W, { x ,y + i }, &COCC::dummy);

	}
}



void COCC::gotoXY()
{
	SetConsoleCursorPosition(SSHO, m_Coord);
}

void COCC::setColor()
{
	SetConsoleTextAttribute(SSHO, m_Color);
}

