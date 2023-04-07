#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"

// 이 파일아닌듯 ㅋㅋ 

// 포인트: 플레이ㅓ를 콘솔게임 오브젝트의 포인터로 사용한다는 점이 중요. 


Player::Player() 
{

}


void Player::Input() // //4. 총알 배열을 순회하며 발사되지 않은 총알을 찾아서 발사하도록 수정해야하는데 방법을 모르겠음.  


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
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
		BulletPtr[0].SetPos(Pos);
		BulletPtr[0].FireOn();
		break;
	default:
		break;
	}

	Sleep(InterFrame);

}


void Player::Render()
{
	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '*');
}