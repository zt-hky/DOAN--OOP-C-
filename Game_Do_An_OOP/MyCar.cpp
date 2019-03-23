#include "MyCar.h"



bool CMyCar::IsEatBons(CBonus _bonus)
{
	COORD bonus;
	for (int i = 0; i < c_MaxBonus; i++)
	{
		if (m_Coord.Y > bonus.Y)
			return false;
		if (m_Coord.X + c_CarW < bonus.X)
			return false;
		if (m_Coord.X > bonus.X)
			return false;
		if (m_Coord.Y + c_CarL < bonus.Y)
			return false;
		return true;
	}
	
}

void CMyCar::MoveUp()
{
	if (m_Coord.Y == c_CarLimitMoveY)
		return;
	m_Coord.Y--;
}

void CMyCar::MoveDown()
{
	if (m_Coord.Y + c_CarL  == c_Race_L_y)
		return;
	m_Coord.Y++;
}

void CMyCar::MoveLeft()
{
	if (m_Coord.X == 0)
		return;
	m_Coord.X--;
}

void CMyCar::MoveRight()
{
	if (m_Coord.X + c_CarW  == c_Race_L_x)
		return;
	m_Coord.X++;
}

void CMyCar::TurnOnNitro()
{
	m_Nitro = true;
}

void CMyCar::TurnOffNitro()
{
	m_Nitro = false;
}

bool CMyCar::GetStateNitro()
{
	return m_Nitro;
}

bool CMyCar::CheckImpact(CSetEnemyCar & _SEC)
{
	for (int i = 0; i < c_MaxECar; i++)
	{
		if (!_SEC.getState(i))
			continue;
		if(IsImpact(_SEC.getCoord(i)))
			return true;
	}
	return false;
}

void CMyCar::UpPoint(int _up)
{
	m_Score += _up;
}

void CMyCar::ResetPoint()
{
	m_Score = 0;
}

int CMyCar::GetScore()
{
	return m_Score;
}



COORD CMyCar::GetCoord()
{
	return m_Coord;
}

void CMyCar::Reset()
{
	m_Score = 0;
	m_Coord.X = c_Race_L_x / 2 - c_CarW / 2;
	m_Coord.Y = c_Race_L_y - c_CarL;
}

CMyCar::CMyCar()
{
	m_Score = 0;
	m_Nitro = false;
}


CMyCar::~CMyCar()
{
}
