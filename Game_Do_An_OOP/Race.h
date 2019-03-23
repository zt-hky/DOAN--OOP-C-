#pragma once

#include "config.h"
#include "OCC.h"
#include "Pixel.h"
#include "Car.h"
#include "MyCar.h"
#include "SetEnemyCar.h"
#include "Bonus.h"

class CRace
{
protected:
	CPixel m_race[2][c_Race_L_x][c_Race_L_y];
	bool m_Update;
	bool m_Layer;
	void Render_Race();
	void Render_EnemyCar(CSetEnemyCar& _setEnemyCar);
	void Render_MyCar(CMyCar& _mycar);
	void Render_Bonus(CBonus& _bonus);
	int m_Time;

	CPixel* get(COORD _coord);
public:
	void UpTime();
	void Render(CMyCar& _myCar, CSetEnemyCar& _setEnemyCar, CBonus& _bonus);
	void Out();
	void OutDiff();
	CRace();
	~CRace();
};

