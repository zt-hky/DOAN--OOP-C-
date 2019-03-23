#include <thread>
#include <iostream>

#include "config.h"
#include "Control.h"
#include "OCC.h"
#include "OutLine.h"
#include "Pixel.h"
#include "Race.h"
#include "MyCar.h"
#include "SetEnemyCar.h"



#pragma once
class CGame
{
protected:

	CMyCar m_MyCar;
	CSetEnemyCar m_SEnemyCar;
	int m_iPoint;
	CRace m_Race;
	bool m_UpdateRace;


public:
	void play();
	CGame();
	~CGame();
};

