#include "ICC.h"

HANDLE CICC::SSHO = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD CICC::dummy = 0x0000;
CONSOLE_CURSOR_INFO CICC::cursor;


void CICC::SetColorCursor(WORD _color)
{
	SetConsoleTextAttribute(CICC::SSHO, _color);
}

int CICC::getString(std::string & _str, COORD _coord, int _lenght, WORD _color)
{
	char Input;
	int n=0;
	CICC::TurnOnCursor();
	CICC::SetColorCursor(_color);
	FillConsoleOutputAttribute(CICC::SSHO, _color, _lenght, _coord, &CICC::dummy);
	
	_str.clear();
	while (true)
	{
		if(n < _lenght)
			CICC::CursorGotoXY(_coord);
		Input = _getch();
		
		if (Input == VK_BACK && n != 0)
		{
			_str.pop_back();
			_coord.X--;
			n--;
			FillConsoleOutputCharacterA(CICC::SSHO, ' ', 1, _coord, &CICC::dummy);
			
		}
		else
			if (Input == VK_RETURN)
			{
				_str.push_back('\0');
				break;
			}
			else
				if (Input >= 32 && Input <= 126 && n < _lenght)
				{
					FillConsoleOutputCharacterA(CICC::SSHO, Input, 1, _coord, &CICC::dummy);
					_str.push_back(Input);
					_coord.X++;
					n++;
				}
	}
	CICC::TurnOffCursor();
	return n;
}
void CICC::TurnOnCursor()
{
	CICC::cursor = { 1,true };
	SetConsoleCursorInfo(CICC::SSHO, &CICC::cursor);
}
void CICC::TurnOffCursor()
{
	CICC::cursor = { 1,false };
	SetConsoleCursorInfo(CICC::SSHO, &CICC::cursor);
}
void CICC::CursorGotoXY(COORD _coord)
{
	SetConsoleCursorPosition(CICC::SSHO, _coord);
}

CICC::CICC()
{
}

CICC::~CICC()
{
}
