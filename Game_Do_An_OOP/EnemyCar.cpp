#include "EnemyCar.h"

void CEnemyCar::SetMove(MOVE _move)
{
	m_Move = _move;
}

// Di chuyển theo trục Y
void CEnemyCar::MoveDown()
{
	m_Coord.Y++;
	if (m_Coord.Y >= c_Race_L_y)
		m_State = false;
}

// Di chuyển theo trục X
void CEnemyCar::MoveX()
{
	if (!m_State) return;
	if (m_Move == LEFT)
	{
		m_Coord.X--;
	}
	if (m_Move == RIGHT)
	{
		m_Coord.X++;
	}
	if (m_Move == DOWN)
	{
		m_Move = LEFT;
	}
}

// Chuyển hướng
void CEnemyCar::DirectionX()
{
	if (m_Move == LEFT)
		m_Move == RIGHT;
	else
		m_Move = LEFT;
}

void CEnemyCar::GetMove(MOVE _move)
{
	m_Move = _move;
}

// Làm đứng im theo trục X
void CEnemyCar::FreezeX()
{
	m_Move == DOWN;
}


// Kiểm tra xe kề nhau
bool CEnemyCar::CheckAdjacent(const CEnemyCar & _EC)
{
	if (m_Coord.X + c_CarW + 1 == _EC.m_Coord.X)
		return true;
	if (_EC.m_Coord.X + c_CarW + 1 == m_Coord.X)
		return true;
	return false;
}

// Khởi tạo
void CEnemyCar::Inil(const COORD& _coord)
{
	m_Coord = _coord;
	m_State = true;
}

void CEnemyCar::Inil(const COORD & _coord,const MOVE& _move)
{
	m_Coord = _coord;
	m_Move = _move;
	m_State = true;
}

bool CEnemyCar::GetState()
{
	return m_State;
}

void CEnemyCar::SetTrueState()
{
	m_State = true;
}

void CEnemyCar::SetFalseState()
{
	m_State = false;
}

bool CEnemyCar::CheckImpactLeft(CEnemyCar & _EC)
{
	return m_State && _EC.m_State && (m_Coord.X <= _EC.m_Coord.X + c_CarW);
}

bool CEnemyCar::CheckImpactRight(CEnemyCar & _EC)
{
	return m_State && _EC.m_State && (m_Coord.X + c_CarW >= _EC.m_Coord.X);
}

COORD & CEnemyCar::getCoord()
{
	return m_Coord;
	// TODO: insert return statement here
}

CEnemyCar::CEnemyCar()
{
	m_State = false;

}


CEnemyCar::~CEnemyCar()
{
}
