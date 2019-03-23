#pragma once
#include "Car.h"
#include "Bonus.h"
#include "config.h"
#include "SetEnemyCar.h"
#include <Windows.h>

class CMyCar :
	public CCar
{
protected:
	bool m_Nitro;
	int m_Score;
public:
	bool IsEatBons(CBonus _bonus);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void TurnOnNitro();
	void TurnOffNitro();
	bool GetStateNitro();
	bool CheckImpact(CSetEnemyCar& _SEC);
	void UpPoint(int _up);
	void ResetPoint();
	int GetScore();
	COORD GetCoord();
	void Reset();
	CMyCar();
	~CMyCar();
};

