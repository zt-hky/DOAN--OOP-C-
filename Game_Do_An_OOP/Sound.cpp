#include "Sound.h"



void CSound::load(std::string _url, std::string _name)
{
	std::string command = "open " + _url + " type mpegvideo alias mpeg";
	mciSendString((LPCWSTR )command.c_str(),NULL,0,0);
}

void CSound::playMP3(std::string _name)
{
	std::string command = "play " + _name;
	mciSendString((LPCWSTR)command.c_str(), NULL, 0, 0);
}

void CSound::playSound()
{
	CSound::load("Sound\\music1.mp3", "mp3_1");
	CSound::playMP3("Sound\\music1.mp3");
}

CSound::CSound()
{
}


CSound::~CSound()
{
}
