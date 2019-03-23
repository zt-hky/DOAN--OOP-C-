#include "ThreadGame.h"



bool CThreadGame::CheckImpactAndEndGame()
{
	if (m_MyCar.CheckImpact(m_SetEnemyCar))
	{
		// Menu end Game
		// **************************
		
		m_State = false;

		WaitForSingleObject(m_hControl, INFINITE);
		WaitForSingleObject(m_hFlowRace, INFINITE);
		WaitForSingleObject(m_hMoveEnemyCar, INFINITE);

		return true;
	}
	return false;
}

bool CThreadGame::CheckEatBonus()
{
	COORD CoordMyCar = m_MyCar.GetCoord(), bonus;
	for (int i = 0; i < c_MaxBonus; i++)
	{ 
		if (m_Bonus.GetCoord(i, bonus))
		{
			if (CoordMyCar.Y > bonus.Y)
				continue;
			if (CoordMyCar.X + c_CarW < bonus.X)
				continue;
			if (CoordMyCar.X > bonus.X)
				continue;
			if (CoordMyCar.Y + c_CarL < bonus.Y)
				continue;
			m_Bonus.SetStateFalse(i);
			m_MyCar.UpPoint(c_upPoint_EatBonus);
			return true;
		}
	}
}

void CThreadGame::LoopControl()
{
	while (!m_Pause && m_State)
	{
		if (Control::CheckKeyEscape() || Control::CheckKeyEnter())
		{
			m_Pause = true;
		}
		if (Control::CheckKeyUp())
		{
			m_MyCar.MoveUp();
			m_UpdateOutput = true;
		}
		if (Control::CheckKeyDown())
		{
			m_MyCar.MoveDown();
			m_UpdateOutput = true;
		}
		if (Control::CheckKeyLeft())
		{
			m_MyCar.MoveLeft();
			m_UpdateOutput = true;
		}
		if (Control::CheckKeyRight())
		{
			m_MyCar.MoveRight();
			m_UpdateOutput = true;
		}
		if (Control::CheckKeySpace())
		{
			m_MyCar.TurnOnNitro();
		}
		else
		{
			m_MyCar.TurnOffNitro();
		}
		_sleep(c_Sleep_Control);

	}
}

void CThreadGame::LoopFlowRace()
{
	srand(time(NULL));
	while (!m_Pause && m_State)
	{
		m_Race.UpTime();
		m_SetEnemyCar.moveDown();
		m_Bonus.Run();

		if (m_Time == 300)
			m_NumberECarInRow = 3;
		if (m_Time == 150)
			m_NumberECarInRow = 2;
		if (m_Time % m_RangeNewEcar == 0)
		{  
			m_SetEnemyCar.CreatNewRow(m_NumberECarInRow);
		}
		if (m_Time % (m_RangeNewEcar/2) == 0)
		{
			m_Bonus.Intil(m_NumberECarInRow);
		}
		m_Time++;
		m_UpdateOutput = true;
		m_MyCar.UpPoint(c_upPoint_flowRace);
		COutLine::OutPoint(m_MyCar.GetScore());

		_sleep(m_SpeedNow* (m_MyCar.GetStateNitro()? c_SupperSpeedNitro:1));
		m_SpeedNow = (m_SpeedNow < c_SpeedLimit) ? c_SpeedLimit : m_SpeedNow*c_SpeedUpFlow;
	}
}

void CThreadGame::LoopMoveEnemyCar()
{
	while (!m_Pause && m_State)
	{
		_sleep(c_Sleep_EnemyCarMove);
		m_SetEnemyCar.moveX();
		m_UpdateOutput = true;
	}
}

void CThreadGame::LoopOutput()
{
	COutLine::draw();
	m_Race.Render(m_MyCar,m_SetEnemyCar,m_Bonus);
	m_Race.Out();
	while (m_State && !m_Pause)
	{
		if (m_UpdateOutput)
		{
			CThreadGame::CheckEatBonus();
			m_Race.Render(m_MyCar, m_SetEnemyCar,m_Bonus);
			m_Race.OutDiff();
			m_UpdateOutput = false;
			CThreadGame::CheckImpactAndEndGame();
		}
		_sleep(c_Sleep_Output);
	}
}

void CThreadGame::Reset()
{
	m_SetEnemyCar.Reset();
	m_MyCar.Reset();
	m_Bonus.Reset();
	m_State = true;
	m_Pause = false;
	m_UpdateOutput = true;
	m_SpeedNow = c_Sleep_FlowRace;
	m_RangeNewEcar = 20;
	m_Time = m_RangeNewEcar;
	m_NumberECarInRow = 1;

}

void CThreadGame::Start()
{
	std::string noti;

	m_threadOuput = std::thread(&CThreadGame::LoopOutput, this);
	m_threadControl = std::thread(&CThreadGame::LoopControl, this);
	m_threadFlowRace = std::thread(&CThreadGame::LoopFlowRace, this);
	m_threadMoveEnemyCar = std::thread(&CThreadGame::LoopMoveEnemyCar, this);

	
	m_threadOuput.join();
	m_threadControl.join();
	m_threadFlowRace.join();
	m_threadMoveEnemyCar.join();

	if (m_Pause)
		noti = "Game Paused";

	while (m_Pause)
	{
		COutLine::draw();
		COutLine::OutPoint(m_MyCar.GetScore());
		m_Race.Out();
		int Select = CMenuGame::MenuPause({ (SHORT)c_Race_O_x + c_Race_L_x / 2 - 15,(SHORT)c_Race_L_y / 3 }, noti.c_str());
		switch (Select)
		{
		case 1:
			m_Pause = false;
			CThreadGame::Start();
			break;
		case 2:
			// Save game
			noti = "Game Saved!";
			break;
		case 3:
			m_Rank.ReadFile();
			CMenuGame::MenuHighScore({ c_Race_L_x / 2 + c_Race_O_x - 23,c_Race_L_y / 2 - 11 }, m_Rank, m_MyCar.GetScore(), "High Score", true);
			break;
		case 4:
			CMenuGame::MenuHelp({ c_Race_L_x / 2 + c_Race_O_x - 24,c_Race_L_y / 2 - 8 });
			break;
		case 5:
			m_Pause = false;
			break;
		}
	}


	if (!m_State)
	{
		Control::ClearKey();
		m_Rank.ReadFile();
		
		std::string noti;

		if (m_Rank.GetN() > 0 && m_MyCar.GetScore() > m_Rank.GetScore(0))
			noti = "NEW RECORD!!!!";
		else
			noti = "GAME OVER";

		std::string name = CMenuGame::MenuInputName({ c_Race_L_x / 2 + c_Race_O_x - 14,c_Race_L_y / 2 - 3 }, noti.c_str());

		
		m_Rank.Push(name, m_MyCar.GetScore());
		m_Rank.WriteFile();
		CMenuGame::MenuHighScore({ c_Race_L_x / 2 + c_Race_O_x - 23,c_Race_L_y / 2 - 11 }, m_Rank, m_MyCar.GetScore(), "High Score", true);

	}
	

}

void CThreadGame::Begin()
{
	int Select;
	CICC::TurnOffCursor();
	while (true)
	{
		COutLine::draw();
		Select = CMenuGame::MainMenu2({ (SHORT)c_Race_O_x + c_Race_L_x / 2 - 15,(SHORT)c_Race_L_y / 3 }, "Menu Game :");

		switch (Select)
		{
		case 1:
			CThreadGame::Reset();
			CThreadGame::Start();
			break;
		case 3:
			m_Rank.ReadFile();
			CMenuGame::MenuHighScore({ c_Race_L_x / 2 + c_Race_O_x - 23,c_Race_L_y / 2 - 11 }, m_Rank, 0, "High Score", false);
			break;
		case 4:
			CMenuGame::MenuHelp({ c_Race_L_x / 2 + c_Race_O_x - 24,c_Race_L_y / 2 - 8 });
			break;
		case 5:
			exit(0);
			break;
		}
	}
}

CThreadGame::CThreadGame()
{
	

}


CThreadGame::~CThreadGame()
 {
	/*TerminateThread(m_hOuput, 0);
	TerminateThread(m_hControl, 0);
	TerminateThread(m_hFlowRace, 0);
	TerminateThread(m_hMoveEnemyCar, 0);*/
	//CloseHandle(m_hOuput);
	//CloseHandle(m_hControl);
	//CloseHandle(m_hFlowRace);
	//CloseHandle(m_hMoveEnemyCar);


}
