#pragma once
#include "config.h"
#include "Car.h"

class CEnemyCar :
	public CCar
{
protected:
	bool m_State;
	MOVE m_Move;
public:
	void SetMove(MOVE _move);
	// Di chuyển trục Y
	void MoveDown();
	// Di chuyển trục X
	void MoveX();
	// Chuyển hướng di chuyển theo trục X
	void DirectionX();
	void GetMove(MOVE _move);
	// Đứng im theo trục X
	void FreezeX();
	bool CheckAdjacent(const CEnemyCar& _EC);
	// Khởi tạo
	void Inil(const COORD& _coord);
	void Inil(const COORD& _coord, const MOVE& _move);
	// lấy state
	bool GetState();
	// set true state
	void SetTrueState();
	
	void SetFalseState();
	// get Coord
	bool CheckImpactLeft(CEnemyCar& _EC);
	bool CheckImpactRight(CEnemyCar& _EC);
	COORD& getCoord();
	CEnemyCar();
	~CEnemyCar();
};

