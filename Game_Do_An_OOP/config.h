#pragma once

#define c_Color_Outline 0x002F
#define c_Color_Race	0x008F
#define c_Color_MyCar	0x0080
#define c_Color_Nitro	0x00CB
#define c_Color_Point	0x0027
#define c_Color_Bonus	0x008E



#define c_Race_L_x	35
#define c_Race_L_y	30
#define c_Race_O_x	20

#define c_SupperSpeedNitro		0.25f
#define c_SpeedUpFlow			0.992f
#define c_SpeedLimit		50

#define c_CarW				5
#define c_CarL				5
#define c_CarLimitMoveY		0
#define c_MaxECar_row		10
#define c_MaxECar_column	3
#define c_MaxECar			c_MaxECar_row*c_MaxECar_column

#define c_MaxBonus			10

#define c_COORD_Pointer		{ c_Race_L_x + c_Race_O_x*2 - 4,7}


#define c_upPoint_flowRace	1
#define c_upPoint_EatBonus	200

enum MOVE		{ UP, DOWN,LEFT,RIGHT };

#define c_Sleep_Control			30
#define c_Sleep_FlowRace		150
#define c_Sleep_EnemyCarMove	350
#define c_Sleep_Output			0

#define c_char_MidRace '|'
#define c_char_Nitro	240
#define c_char_Bonus '$'


#define c_FileSave		"save"
#define c_FileScore		"rank"
#define c_MaxLenghtName		20


#define c_StrMainMenu	{{" NEW GAME ","HIGH SCORE","   HELP   ","   EXIT   "}, {" NEW GAME ","  RESUME  ","HIGH SCORE","   HELP   ","   EXIT   "},{"  RESUME  ","   SAVE   ","HIGH SCORE","   HELP   ","MAIN MENU "}}

const unsigned char c_str_MyCar[5][5] =
{
	{201,220,203,220,187},
	{204,205,202,205,185 },
	{186,219,219,219,186},
	{204,203,207,203,185},
	{200,208,196,208,188}
};

//		╔▄╦▄╗		╓┬─┬╖		
//		╠═╩═╣		╠╧╤╧╣
//		║░░░║		║░░░║
//		╠╦╧╦╣		╠═══╣
//		╚╨─╨╝		╚▀═▀╝

