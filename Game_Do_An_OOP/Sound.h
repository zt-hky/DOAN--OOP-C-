#pragma once

#include <string>
#include <Windows.h>
#include <Mmsystem.h>
#include <mciapi.h>


class CSound
{
protected:
	static void load(std::string _url, std::string _name);
	static void playMP3(std::string _url);
public:
	static void playSound();
	CSound();
	~CSound();
};

