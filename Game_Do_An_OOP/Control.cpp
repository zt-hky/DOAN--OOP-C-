#include "Control.h"

HANDLE Control::m_hSTDInput = GetStdHandle(STD_INPUT_HANDLE);

bool Control::CheckKeyUp()
{
	return GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(0x57) & 0x8000;
}

bool Control::CheckKeyDown()
{
	return GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(0x53) & 0x8000;
}

bool Control::CheckKeyLeft()
{
	return GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(0x41) & 0x8000;
}

bool Control::CheckKeyRight()
{
	return GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(0x44) & 0x8000;
}

bool Control::CheckKeyEscape()
{
	return GetAsyncKeyState(VK_ESCAPE) & 0x8000;
}

bool Control::CheckKeyEnter()
{
	return GetAsyncKeyState(VK_RETURN) & 0x8000;
}

bool Control::CheckKeySpace()
{
	return GetAsyncKeyState(VK_SPACE) & 0x8000;
}

void Control::ClearKey()
{
	FlushConsoleInputBuffer(m_hSTDInput);
}
