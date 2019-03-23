#include "Bonus.h"




bool CBonus::GetCoord(int i, COORD & _coord)
{
	if (!m_State[i]) return false;
	_coord = m_Coord[i];
	return true;
}

void CBonus::Run()
{
	for (int i = 0;i < c_MaxBonus;i++)
	{
		if (m_State[i])
		{
			m_Coord[i].Y++;
			if (m_Coord[i].Y == c_Race_L_y)
				m_State[i] = false;
		}
	}
}

void CBonus::Intil(int n)
{
	int k = 0;
	for (int i = 0; i < c_MaxBonus && k < n ; i++)
	{
		if (!m_State[i])
		{
			m_Coord[i].Y = 0;
			m_Coord[i].X = rand() % c_Race_L_x;
			k++;
			m_State[i] = true;
		}
	}
}

void CBonus::Reset()
{
	for (int i = 0; i < c_MaxBonus; i++)
		m_State[i] = false;
}

void CBonus::SetStateFalse(int i)
{
	m_State[i] = false;
}





CBonus::CBonus()
{
}


CBonus::~CBonus()
{
}
