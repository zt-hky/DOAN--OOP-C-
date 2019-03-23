#include "SetEnemyCar.h"



void CSetEnemyCar::moveDown()
{
	for (int i = 0; i < c_MaxECar; i++)
	{
		if (m_ECar[i].GetState())
			m_ECar[i].MoveDown();
	}
}

void CSetEnemyCar::moveX()
{
	int check;
	int rowX0;
	int iNow;
	for (int i = 0; i < c_MaxECar_row; i++)
	{
		if (m_ECar[i*c_MaxECar_column].GetState())
		{
			for (int j = 0; j < c_MaxECar_column; j++)
			{
				check = 0;
				iNow = i*c_MaxECar_column + j;
				if (m_ECar[iNow].GetState())
				{
					if (m_ECar[iNow].getCoord().X == 0)
					{
						check++;
						m_ECar[iNow].SetMove(RIGHT);
					}
					else if ( j !=0 && m_ECar[iNow].CheckImpactLeft(m_ECar[iNow - 1]))
					{
						check++;
						m_ECar[iNow].SetMove(RIGHT);
					}
				}

				if (m_ECar[iNow].getCoord().X + c_CarW == c_Race_L_x)
				{
					check++;
					m_ECar[iNow].SetMove(LEFT);
				}
				else
				{
					if (j != c_MaxECar_column - 1 && m_ECar[iNow].CheckImpactRight(m_ECar[iNow + 1]))
					{
						check++;
						m_ECar[iNow].SetMove(LEFT);
					}
				}

				if (check == 2)
					m_ECar[iNow].FreezeX();
			}
		}
	}
	for (int i = 0; i < c_MaxECar; i++)
	{
		m_ECar[i].MoveX();
	}
}


void CSetEnemyCar::CreatNewRow(int member)
{
	int row = 0, irand;
	MOVE mMove;
	COORD coord;
	for (int i = 0; i < c_MaxECar_row; i++)
	{
		if (!m_ECar[i*c_MaxECar_column].GetState())
		{
			row = i;
			break;
		}
	}
	for (int i = 0; i < member; i++)
	{
		int landRand = c_Race_L_x / member;
		irand = rand();
		coord.Y = -c_CarL + irand % c_CarL;
		coord.X = irand % (landRand - c_CarW + 1) + i*(c_Race_L_x/member);
		if (irand % 2 == 0)
		{
			mMove = LEFT;
		}
		else
		{
			mMove = RIGHT;
		}
		m_ECar[row*c_MaxECar_column + i].Inil(coord, mMove);
	}

}

void CSetEnemyCar::Reset()
{
	for (int i = 0; i < c_MaxECar; i++)
		m_ECar[i].SetFalseState();
}

COORD& CSetEnemyCar::getCoord(int i)
{
	return m_ECar[i].getCoord();
	// TODO: insert return statement here
}

bool CSetEnemyCar::getState(int i)
{
	return m_ECar[i].GetState();
	// TODO: insert return statement here
}

CSetEnemyCar::CSetEnemyCar()
{

}


CSetEnemyCar::~CSetEnemyCar()
{
}
