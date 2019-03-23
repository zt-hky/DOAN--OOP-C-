#pragma once

#include "config.h"
#include <Windows.h>

class CCar
{
protected:
	COORD m_Coord;
public:
	bool IsReal();
	bool IsImpact(CCar _car);
	bool IsImpact(COORD _coord);
	CCar();
	~CCar();
};