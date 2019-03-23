#include "MenuGame.h"

std::string CMenuGame::m_StrMainMenu[3][5] = c_StrMainMenu;

std::string CMenuGame::NameOut(std::string _name)
{
	int L = _name.length();
	for (; L < 37; L++)
	{
		_name.push_back('_');
	}
	return _name;
}

int CMenuGame::MainMenu1(COORD _coord, const char* _str)
{

	//	╔════════════════════════════╗
	//	║							 ║
	//	║          NEW GAME          ║
	//	║                            ║
	//	║           RESUME           ║
	//	║                            ║
	//	║         HIGH SCORE         ║
	//	║                            ║
	//	║            HELP            ║
	//	║                            ║
	//	║            EXIT            ║
	//	║                            ║
	//	╚════════════════════════════╝

	COCC::Border(_coord, 0x000B, 30, 13);
	COCC::OutStr(_str, { _coord.X + 2,_coord.Y }, 0x0002);

	for (SHORT i = 1; i <= 11; i++)
	{
		COCC::Fill(' ', 28, { _coord.X + 1,_coord.Y + i }, 0x000F);
	}
	for (SHORT i = 0; i < 5; i++)
	{
		COCC::OutStringC(m_StrMainMenu[1][i], { _coord.X + 10,_coord.Y + 2 * (i + 1) });
	}

	SHORT select = 1, key;

	while (true)
	{
		COCC::FillA(COLOR_Select, 12, { _coord.X + 9,_coord.Y + 2 * (select) });
		_sleep(SleepWaitKey);
		Control::ClearKey();
		if (_getch() == 224)
			_getch();

		if (Control::CheckKeyUp())
		{
			COCC::FillA(COLOR_unSelect, 12, { _coord.X + 9,_coord.Y + 2 * (select) });
			select--;
			if (select < 1)select = 5;
		}
		if (Control::CheckKeyDown())
		{
			COCC::FillA(COLOR_unSelect, 12, { _coord.X + 9,_coord.Y + 2 * (select) });
			select++;
			if (select > 5) select = 1;
		}
		if (Control::CheckKeyEnter() || Control::CheckKeySpace())
		{
			break;
		}


	}
	for (int i = 0; i < 5; i++)
	{
		COCC::FillA(COLOR_Select, 12, { _coord.X + 9,_coord.Y + 2 * (select) });
		_sleep(55);
		COCC::FillA(COLOR_unSelect, 12, { _coord.X + 9,_coord.Y + 2 * (select) });
		_sleep(55);
	}
	return select;

}

int CMenuGame::MainMenu2(COORD _coord, const char* _str)
{
	//	╔════════════════════════════╗
	//	║							 ║
	//	║							 ║
	//	║          NEW GAME          ║
	//	║                            ║
	//	║         HIGH SCORE         ║
	//	║                            ║
	//	║            HELP            ║
	//	║                            ║
	//	║            EXIT            ║
	//	║                            ║
	//	║                            ║
	//	╚════════════════════════════╝

	COCC::Border(_coord, 0x000B, 30, 13);
	COCC::OutStr(_str, { _coord.X + 2,_coord.Y }, 0x0002);

	for (SHORT i = 1; i <= 11; i++)
	{
		COCC::Fill(' ', 28, { _coord.X + 1,_coord.Y + i }, 0x000F);
	}
	for (SHORT i = 0; i < 5; i++)
	{
		COCC::OutStringC(m_StrMainMenu[0][i], { _coord.X + 10,_coord.Y + 2 * (i + 1) + 1 });
	}

	SHORT select = 1, key;

	while (true)
	{
		COCC::FillA(COLOR_Select, 12, { _coord.X + 9,_coord.Y + 2 * (select)+1 });

		_sleep(SleepWaitKey);
		if (_getch() == 224)
			_getch();
		if (Control::CheckKeyUp())
		{
			COCC::FillA(COLOR_unSelect, 12, { _coord.X + 9,_coord.Y + 2 * (select)+1 });
			select--;
			if (select < 1)select = 4;
		}
		if (Control::CheckKeyDown())
		{
			COCC::FillA(COLOR_unSelect, 12, { _coord.X + 9,_coord.Y + 2 * (select)+1 });
			select++;
			if (select > 4) select = 1;
		}
		if (Control::CheckKeyEnter() || Control::CheckKeySpace())
		{
			break;
		}

	}
	for (int i = 0; i < 5; i++)
	{
		COCC::FillA(COLOR_Select, 12, { _coord.X + 9,_coord.Y + 2 * (select)+1 });
		_sleep(55);
		COCC::FillA(COLOR_unSelect, 12, { _coord.X + 9,_coord.Y + 2 * (select)+1 });
		_sleep(55);
	}
	if (select >= 2)
		return select + 1;
	return select;
}

int CMenuGame::MenuPause(COORD _coord, const char * _str)
{
	//	╔════════════════════════════╗
	//	║							 ║
	//	║           RESUME           ║
	//	║                            ║
	//	║            SAVE            ║
	//	║                            ║
	//	║         HIGH SCORE         ║
	//	║                            ║
	//	║            HELP            ║
	//	║                            ║
	//	║          MAIN MENU         ║
	//	║                            ║
	//	╚════════════════════════════╝

	COCC::Border(_coord, 0x000B, 30, 13);
	COCC::OutStr(_str, { _coord.X + 1,_coord.Y }, 0x0002);

	for (SHORT i = 1; i <= 11; i++)
	{
		COCC::Fill(' ', 28, { _coord.X + 1,_coord.Y + i }, 0x000F);
	}
	for (SHORT i = 0; i < 5; i++)
	{
		COCC::OutStringC(m_StrMainMenu[2][i], { _coord.X + 10,_coord.Y + 2 * (i + 1) });
	}

	SHORT select = 1, key;

	while (true)
	{
		COCC::FillA(COLOR_Select, 12, { _coord.X + 9,_coord.Y + 2 * (select) });
		_sleep(SleepWaitKey);
		Control::ClearKey();
		if (_getch() == 224)
			_getch();

		if (Control::CheckKeyUp())
		{
			COCC::FillA(COLOR_unSelect, 12, { _coord.X + 9,_coord.Y + 2 * (select) });
			select--;
			if (select < 1)select = 5;
		}
		if (Control::CheckKeyDown())
		{
			COCC::FillA(COLOR_unSelect, 12, { _coord.X + 9,_coord.Y + 2 * (select) });
			select++;
			if (select > 5) select = 1;
		}
		if (Control::CheckKeyEnter() || Control::CheckKeySpace())
		{
			break;
		}


	}
	for (int i = 0; i < 5; i++)
	{
		COCC::FillA(COLOR_Select, 12, { _coord.X + 9,_coord.Y + 2 * (select) });
		_sleep(55);
		COCC::FillA(COLOR_unSelect, 12, { _coord.X + 9,_coord.Y + 2 * (select) });
		_sleep(55);
	}
	return select;
}

void CMenuGame::MenuHighScore(COORD _coord, CRank & _rank, int _myScore, const char* _str, bool isPause)
{

	//	╔═High Score═════════════════════════════════╗
	//	║                                            ║
	//	║   1. Zungtazswersdfrasfdg..........30144   ║
	//	║                                            ║
	//	║   2. Zungtazswersdfrasfdg..........30144   ║                                      
	//	║                                            ║
	//	║   3. Zungtazswersdfrasfdg..........30144   ║                                  
	//	║                                            ║
	//	║   4. Zungtazswersdfrasfdg..........30144   ║                                       
	//	║                                            ║
	//	║   5. Zungtazswersdfrasfdg..........30144   ║                                     
	//	║                                            ║
	//	║   6. Zungtazswersdfrasfdg..........30144   ║                                     
	//	║                                            ║
	//	║   7. Zungtazswersdfrasfdg..........30144   ║                 
	//	║                                            ║
	//	║   8. Zungtazswersdfrasfdg..........30144   ║                 
	//	║                                            ║
	//	║   9. Zungtazswersdfrasfdg..........30144   ║                                     
	//	║                                            ║
	//	║  10. Zungtazswersdfrasfdg..........30144   ║                                     
	//	║                                            ║
	//	╚════════════════════════════════════════════╝

	int PageNow, SumPage, N, iMyScore, iUpScore, iLowScore;
	SHORT i;
	N = _rank.GetN();
	PageNow =0;
	SumPage = (N-1) / 10 +1 ;
	iMyScore = -1;
	iUpScore = -1;
	iLowScore = -1;

	COCC::BorderFillBackground(_coord, 0x000B, 46, 23);
	COCC::OutStr(_str, { _coord.X + 2,_coord.Y }, 0x0002);
	
	if (isPause)
	{
		for (i = 0; i < N; i++)
		{
			if (_myScore >= _rank.GetScore(i))
			{
				break;
			}
		}

		PageNow = i / 10;

		if (i < N &&_myScore == _rank.GetScore(i))
		{
			iMyScore = i;
			if (i > 0)
				iUpScore = i - 1;
			if (i + 1 < N)
				iLowScore = i + 1;

		}
		else
		{
			if (i < N)
			{
				iLowScore = i;
			}
			if (i > 0)
			{
				iUpScore = i - 1;
			}
		}

	}
	
	while (true)
	{
		for (i = 0; i < 10; i++)
		{
			COCC::FillC(' ', 44, { _coord.X + 1,_coord.Y + 2 * (i + 1) });
			COCC::FillA(CMenuGame::colorRank(i + PageNow * 10, iMyScore, iUpScore, iLowScore), 44, { _coord.X + 1,_coord.Y + 2 * (i + 1) });
			if (i + PageNow * 10 >= N) continue;
			
			COCC::OutInt(int(i + PageNow * 10 +1), { _coord.X + 6,_coord.Y + 2 * (i+1) });
			COCC::OutStringC(". "+_rank.GetName(i + PageNow * 10), { _coord.X + 7,_coord.Y + 2 * (i + 1) });
			COCC::OutInt(_rank.GetScore(i + PageNow * 10), { _coord.X + 40,_coord.Y + 2 * (i + 1) });
		}
		if (_getch() == 224)
			_getch();

		if (Control::CheckKeyLeft() || Control::CheckKeyUp())
		{
			PageNow--;
			if (PageNow < 0)
				PageNow = SumPage - 1;
		}
		if (Control::CheckKeyDown() || Control::CheckKeyRight())
		{
			PageNow++;
			if (PageNow == SumPage )
				PageNow = 0;
			
		}
		if (Control::CheckKeyEnter() || Control::CheckKeyEscape())
		{
			break;
		}
	}

}

std::string CMenuGame::MenuInputName(COORD _coord,const char* _str)
{
	std::string name;
	COCC::BorderFillBackground(_coord, 0x000B, 28, 7);
	COCC::OutStr(_str, { _coord.X + 9,_coord.Y }, 0x006C);
	COCC::OutStr("Input Your Namme :", { _coord.X + 5,_coord.Y+2 }, 0x0007);
	CICC::getString(name, { _coord.X + 4, _coord.Y + 4 }, 20, 0x0070);
	return name;
}

void CMenuGame::MenuHelp(COORD _coord)
{
	COCC::BorderFillBackground(_coord, 0x000B, 48, 17);
	COCC::OutStr("HELP", { _coord.X + 9,_coord.Y }, 0x006C);

	COCC::OutStr("Control:", { _coord.X + 5,_coord.Y +2 }, 0x0071);
	COCC::OutStr("Press 'W' or  UP   key : move car Up", { _coord.X + 2,_coord.Y + 4 }, 0x000F);
	COCC::OutStr("Press 'S' or DOWN  key : move car Down", { _coord.X + 2,_coord.Y + 5 }, 0x000F);
	COCC::OutStr("Press 'A' or LEFT  key : move car Left", { _coord.X + 2,_coord.Y + 6 }, 0x000F);
	COCC::OutStr("Press 'D' or RIGHT key : move car Right", { _coord.X + 2,_coord.Y + 7 }, 0x000F);
	COCC::OutStr("Press \"Space Key\"    : Turn Nitro Car", { _coord.X + 2,_coord.Y + 8 }, 0x000F);
	COCC::OutStr("Press Esc or Enter key : Pause Game", { _coord.X + 2,_coord.Y + 9 }, 0x000F);
	_getch();
}

WORD CMenuGame::colorRank(int i, int iMy, int iUp, int iLow)
{
	if (i == 0)
		return COLOR_TOP1;
	if (i == 1)
		return COLOR_TOP2;
	if (i == 2)
		return COLOR_TOP3;

	if (i == iMy)
		return COLOR_RankMy;
	if (i == iUp)
		return COLOR_RankUp;
	if (i == iLow)
		return COLOR_RankLow;
	return COLOR_RankNormal;
}

CMenuGame::CMenuGame()
{
}


CMenuGame::~CMenuGame()
{
}
