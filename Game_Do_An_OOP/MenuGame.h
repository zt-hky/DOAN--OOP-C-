#pragma once
#include "ICC.h"
#include "OCC.h"
#include "config.h"
#include "Control.h"
#include "Rank.h"

#include <iostream>
#include <string>

#define COLOR_Select 0x007C
#define COLOR_unSelect 0x000F
#define SleepWaitKey	60
#define COLOR_RankMy 0x00D	
#define COLOR_RankUp 0x00C
#define COLOR_RankLow 0x00E
#define COLOR_RankNormal 0x00F
#define COLOR_TOP1	0x00C0
#define COLOR_TOP2	0x00E0
#define COLOR_TOP3	0x0010

class CMenuGame
{
protected:
	static std::string m_StrMainMenu[3][5];
	static std::string NameOut(std::string _name);
	static WORD colorRank(int i, int iMy, int iUp, int iLow);
public:
	static int MainMenu1(COORD _coord, const char* _str);
	static int MainMenu2(COORD _coord, const char* _str);
	static int MenuPause(COORD _coord, const char* _str);
	static void MenuHighScore(COORD _coord, CRank& _rank, int _myScore, const char* _str, bool isPause);
	static std::string MenuInputName(COORD _coord, const char* _str);
	static void MenuHelp(COORD _coord);
	CMenuGame();
	~CMenuGame();
};

