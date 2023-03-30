#include "player.h"
#include "Consolegamescreen.h"
#include <conio.h>
#include <Windows.h>

player::player()
{

}

void player::Input()
{
	if (0 == _kbhit())
	{
		Sleep(InterFrame);
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == Consolegamescreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == Consolegamescreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == Consolegamescreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == Consolegamescreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	default:
		break;
	}

	Sleep(InterFrame);
}
