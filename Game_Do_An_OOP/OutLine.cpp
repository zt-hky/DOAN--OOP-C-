#include "OutLine.h"


COORD COutLine::m_cPoint = c_COORD_Pointer;


void COutLine::draw()
{
	
	
	COCC::gotoXY({ 0,0 });
	for (int i = 0; i < c_Race_L_y; i++)
	{
		COCC::Fill(' ', c_Race_O_x-1, {(SHORT) 0,(SHORT)i }, c_Color_Outline);
		COCC::Fill(178, 1, { (SHORT)c_Race_O_x- 1,(SHORT)i }, c_Color_Race);

		COCC::Fill(' ', c_Race_L_x, { (SHORT)c_Race_O_x,(SHORT)i }, c_Color_Race);
		
		COCC::Fill(178, 1, { (SHORT)c_Race_O_x+c_Race_L_x,(SHORT)i }, c_Color_Race);
		COCC::Fill(' ', c_Race_O_x - 1, { (SHORT)c_Race_O_x + c_Race_L_x+1,(SHORT)i }, c_Color_Outline);
	}
}

void COutLine::OutPoint(int n)
{
	COCC::OutInt(n, m_cPoint, c_Color_Point);
}

COutLine::COutLine()
{
}


COutLine::~COutLine()
{
}
