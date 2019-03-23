#include "Game.h"



void CGame::play()
{
	m_MyCar.Init();
	COutLine::draw();
	while (true)
	{
		m_UpdateRace = true;
		
		if (Control::CheckKeyUp())
			m_MyCar.MoveUp();
		if (Control::CheckKeyDown())
			m_MyCar.MoveDown();
		if (Control::CheckKeyLeft())
			m_MyCar.MoveLeft();
		if (Control::CheckKeyRight())
			m_MyCar.MoveRight();

		if (m_UpdateRace)
		{
			m_Race.UpTime();
			m_Race.Render(m_MyCar);
			m_Race.OutDiff();
		}
		_sleep(30);
	}
}


CGame::CGame()
{
}


CGame::~CGame()
{
}
