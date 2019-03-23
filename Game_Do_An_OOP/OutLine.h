#pragma once

#include "Pixel.h"
#include "OCC.h"
#include "config.h"

class COutLine
{
protected:
	static COORD m_cPoint;

public:
	static void draw();
	static void OutPoint(int n);
	COutLine();
	~COutLine();
};
