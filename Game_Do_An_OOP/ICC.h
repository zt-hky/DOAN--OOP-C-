#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>

class CICC
{
protected:
	static HANDLE SSHO;
	static DWORD dummy;
	static CONSOLE_CURSOR_INFO cursor;
public:
	static void SetColorCursor(WORD _color);
	static int getString(std::string& _str, COORD _coord, int _lenght, WORD _color);
	static void TurnOnCursor();
	static void TurnOffCursor();
	static void CursorGotoXY(COORD _coord);
	CICC();
	~CICC();
};

