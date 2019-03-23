#pragma once
#include <vector>
#include <string>
#include "config.h"
#include <fstream>
#include <iostream>

class CRank
{
protected:
	std::vector <std::string>	m_strName;
	std::vector <int>	m_iScore;
	int m_iN;
	
	
public:
	void Push(std::string _strName, int _point);
	bool ReadFile();
	void WriteFile();
	void Out();
	int GetScore(int i);
	std::string GetName(int i);
	int GetN();
	CRank();
	~CRank();
};

