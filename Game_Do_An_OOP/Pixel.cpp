#include "Pixel.h"


CPixel& CPixel::operator=(const CPixel &_pixel)
{
	m_Char = _pixel.m_Char;
	m_Color = _pixel.m_Color;
	m_Coord = _pixel.m_Coord;
	return *this;
}

bool CPixel::operator==(const CPixel & _pixel)
{
	if (m_Char == _pixel.m_Char && m_Color == _pixel.m_Color && m_Coord.X == _pixel.m_Coord.X && m_Coord.Y == _pixel.m_Coord.Y)
		return true;
	return false;
}

void CPixel::out()
{
	FillConsoleOutputCharacterA(SSHO, m_Char, 1, m_Coord, &COCC::dummy);
	FillConsoleOutputAttribute(SSHO, m_Color, 1, m_Coord, &COCC::dummy);
}

void CPixel::outIfDiffCharColor(const CPixel & x)
{
	if (m_Char != x.m_Char)
		COCC::FillC(m_Char, 1, m_Coord);
	if (m_Color != x.m_Color)
		COCC::FillA(m_Color, 1, m_Coord);
}


void CPixel::setXY(COORD _coord)
{
	m_Coord = _coord;
}

void CPixel::set(const unsigned char  _char, int _x, int _y, char _colorFont, char _colorBack)
{
	m_Char = char(_char);
	_colorBack &= 0x0f;
	_colorFont &= 0x0f;
	m_Color = _colorBack;
	m_Color <<= 4;
	m_Color |= _colorFont;
	m_Coord = { (SHORT)_x,(SHORT)_y };
}

void CPixel::set(const unsigned char _char, int _x, int _y, WORD _color)
{
	m_Char = (char)_char;
	m_Coord.X = _x;
	m_Coord.Y = _y;
	m_Color = _color;
}

void CPixel::set(const unsigned char _char, COORD _coord, WORD _color)
{
	m_Char = (char)_char;
	m_Color =  _color;
	m_Coord = _coord;
}

void CPixel::setChar(const unsigned char & _char)
{
	m_Char = (char)_char;
}

void CPixel::setColor(WORD _color)
{
	m_Color = _color;
}

void CPixel::set(unsigned char _char, WORD _color)
{
	m_Char = _char;
	m_Color = _color;
}

CPixel::CPixel()
{
}


CPixel::~CPixel()
{
}
