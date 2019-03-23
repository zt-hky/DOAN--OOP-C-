#include "Race.h"



void CRace::Render_Race()
{
	for (int i = 0; i < c_Race_L_x; i++)
	{
		for (int j = 0; j < c_Race_L_y; j++)
		{
			m_race[m_Layer][i][j].set(' ', c_Color_MyCar);
		}
	}
	int coordMidX = c_Race_L_x / 2;
	for (int i = m_Time; i < c_Race_L_y; i += 3)
	{
		m_race[m_Layer][coordMidX][i].set(c_char_MidRace,c_Color_Race);
	}
}

void CRace::Render_EnemyCar(CSetEnemyCar& _setEnemyCar)
{
	COORD _coord;
	int i, j;
	for (int z = 0; z < c_MaxECar; z++)
	{
		if (_setEnemyCar.getState(z))
		{
			_coord = _setEnemyCar.getCoord(z);
			for (i = 0; i < c_CarL; i++)
			{
				if (_coord.Y + i < 0 || _coord.Y + i >= c_Race_L_y) continue;
				for (j = 0; j < c_CarW; j++)
				{
					m_race[m_Layer][_coord.X + j][_coord.Y + i].set(c_str_MyCar[i][j], c_Color_MyCar);
				}

			}
		}
	}
}

void CRace::Render_MyCar(CMyCar& _mycar)
{
	COORD _coord = _mycar.GetCoord();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			m_race[m_Layer][_coord.X + i][_coord.Y + j].set(c_str_MyCar[j][i], c_Color_MyCar);

	}
	if (_mycar.GetStateNitro())
	{
		m_race[m_Layer][_coord.X + 1][_coord.Y + c_CarL -1 ].setColor(c_Color_Nitro);
		m_race[m_Layer][_coord.X + 3][_coord.Y + c_CarL -1 ].setColor(c_Color_Nitro);
	}
}

void CRace::Render_Bonus(CBonus& _bonus)
{
	COORD coordtmp;
	for (int i = 0; i < c_MaxBonus; i++)
	{
		if (_bonus.GetCoord(i, coordtmp))
		{
			CRace::get(coordtmp)->set(c_char_Bonus, c_Color_Bonus);
		}
	}
		
}






CPixel* CRace::get(COORD _coord)
{
	return &m_race[m_Layer][_coord.X][_coord.Y];
	// TODO: insert return statement here
}

void CRace::UpTime()
{
	m_Time = m_Time == 3 ? 0 : ++m_Time;
}

void CRace::Render(CMyCar & _myCar, CSetEnemyCar & _setEnemyCar, CBonus& _bonus)
{
	m_Layer = !m_Layer;
	
	Render_Race();

	Render_Bonus(_bonus);
	Render_EnemyCar(_setEnemyCar);
	Render_MyCar(_myCar);
	
	m_Update = true;
}


void CRace::Out()
{
	for (int i = 0; i < c_Race_L_x; i++)
	{
		for (int j = 0; j < c_Race_L_y; j++)
		{
			m_race[m_Layer][i][j].out();
		}
	}
}

void CRace::OutDiff()
{
	if (!m_Update) return;
	bool Now = m_Layer, Previous = !m_Layer;
	for (int i = 0; i < c_Race_L_x; i++)
	{
		for (int j = 0; j < c_Race_L_y; j++)
		{
			m_race[Now][i][j].outIfDiffCharColor(m_race[Previous][i][j]);
		}
	}
}

CRace::CRace()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < c_Race_L_x; j++)
		{
			for (int k = 0; k < c_Race_L_y; k++)
				m_race[i][j][k].set(' ', j + c_Race_O_x, k, c_Color_Race);
		}
	}
	m_Update = false;
	m_Time = 0;
	m_Layer = 0;
}


CRace::~CRace()
{
	
}
