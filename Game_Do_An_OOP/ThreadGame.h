#pragma once

#include <iostream>
#include <thread>
#include <time.h>
#include <string>

#include "config.h"

#include "MyCar.h"
#include "SetEnemyCar.h"
#include "OutLine.h"
#include "Race.h"
#include "Bonus.h"
#include "Control.h"
#include "Race.h"
#include "Rank.h"
#include "ICC.h"
#include "MenuGame.h"

class CThreadGame
{
protected:
	bool m_Pause;
	bool m_UpdateOutput;
	bool m_State;

	int m_RangeNewEcar;
	int m_NumberECarInRow;
	int m_Time;
	float m_SpeedNow;

	CRace m_Race;
	CMyCar m_MyCar;
	CSetEnemyCar m_SetEnemyCar;
	CBonus m_Bonus;
	CRank m_Rank;

	std::thread m_threadControl;
	std::thread m_threadFlowRace;
	std::thread m_threadMoveEnemyCar;
	std::thread m_threadOuput;
	
	HANDLE m_hControl;
	HANDLE m_hFlowRace;
	HANDLE m_hMoveEnemyCar;
	HANDLE m_hOuput;

	bool CheckImpactAndEndGame();
	bool CheckEatBonus();
	void LoopControl();
	void LoopFlowRace();
	void LoopMoveEnemyCar();
	void LoopOutput();
	void Start();
	void Reset();
public:
	
	void Begin();
	CThreadGame();
	~CThreadGame();
};

