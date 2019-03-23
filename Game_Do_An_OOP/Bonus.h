#pragma once

#include <Windows.h>
#include "config.h"

class CBonus
{
protected:
	COORD m_Coord[c_MaxBonus];
	bool m_State[c_MaxBonus] = { false };
public:
	// Return Coord Bonus
	bool GetCoord(int i, COORD& _coord);
	// Move Down Bonus
	void Run();
	// Intil
	void Intil(int n);
	void Reset();
	void SetStateFalse(int i);
	CBonus();
	~CBonus();
};

