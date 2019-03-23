#include "Car.h"



bool CCar::IsReal()
{
	if (m_Coord.X < 0 || m_Coord.Y < 0)
		return false;
	if (m_Coord.X + c_CarW < c_Race_L_x)
		return false;
	if (m_Coord.Y + c_CarL < c_Race_L_y)
		return false;
	return true;
}

bool CCar::IsImpact(CCar _car)
{
	if (m_Coord.X + c_CarW < _car.m_Coord.X)
		return false;
	if (m_Coord.X > _car.m_Coord.X + c_CarW)
		return false;
	if (m_Coord.Y + c_CarW < _car.m_Coord.Y)
		return false;
	if (m_Coord.Y > _car.m_Coord.Y + c_CarW)
		return false;
	return true;
}

bool CCar::IsImpact(COORD _coord)
{
	if (m_Coord.Y > _coord.Y + c_CarL -1)
		return false;
	if (m_Coord.Y + c_CarL -1 < _coord.Y)
		return false;
	if (m_Coord.X + c_CarW -1 < _coord.X)
		return false;
	if (m_Coord.X > _coord.X + c_CarW -1)
		return false;	
	return true;
}

CCar::CCar()
{
}


CCar::~CCar()
{
}
