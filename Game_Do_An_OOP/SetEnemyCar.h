#pragma once

#include <stdlib.h>
#include <Windows.h>
#include "EnemyCar.h"
#include "config.h"
#include <time.h>

class CSetEnemyCar
{
private:
	CEnemyCar m_ECar[c_MaxECar];

public: 
	void moveDown();
	void moveX();
	void CreatNewRow(int member);
	void Reset();
	COORD& getCoord(int i);
	bool getState(int i);
	CSetEnemyCar();
	~CSetEnemyCar();
};


