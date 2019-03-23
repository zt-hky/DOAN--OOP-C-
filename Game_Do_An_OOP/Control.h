#pragma once

#include <Windows.h>
#include "config.h"


class Control
{
protected:
	static HANDLE m_hSTDInput;
public:
	static bool CheckKeyUp();
	static bool CheckKeyDown();
	static bool CheckKeyLeft();
	static bool CheckKeyRight();
	static bool CheckKeyEscape();
	static bool CheckKeyEnter();
	static bool CheckKeySpace();
	static void ClearKey();
};

