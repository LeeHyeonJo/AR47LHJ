#include "ShootingGame.h"

#include <iostream>

// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// 게임이 시작하기 전에 준비한다.
	// 총알이 여러발 나가게 만드세요.

	// 시작하면 어차피 모든 총알은 발사되지 않았을것이므로 다 끈다.
	Bullet::AllOff();

	// 플레이어가 총알의 포인터를 알게 한다.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// 플레이어를 화면의 중앙에 위치시킨다.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({i + 3, 1});
	}

}

void ShootingGame::Collision()
{

	Bullet* BulletArr = Bullet::GetArrBullet();

	// 모든 총알과
	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		Bullet& CurBullet = BulletArr[BulletIndex];

		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = ArrMonster[MonsterIndex];

			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				CurMonster.Off();
				CurBullet.Off();
			}
		}
	}

}

//0331 과제: monster의 움직임 구현하기.  


void ShootingGame::MonsterEndCheck() 
{
	int2 leftMostMonsterPos = ArrMonster[0].GetPos();  // 가장 왼쪽의 몬스터 
	int2 rightMostMonsterPos = ArrMonster[ArrMonsterCount - 1].GetPos(); // 가장 오른쪽의 몬스터 

	// 1. 몬스터의 움직임
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].Move({ 1 * ArrMonster[i].GetDir(), 0 }); // Monster::Move()는 Monster.h에 작성. 
	}

	// 2. 몬스터 중 가장 왼쪽 끝과 오른쪽 끝의 위치를 체크
	if (leftMostMonsterPos.x <= 1 || rightMostMonsterPos.x >= ConsoleGameScreen::GetMainScreen().GetScreenSize().x - 2)
	{
		// 3. 끝에 닿았다면, 방향을 바꾼다 
		for (int i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].SetDir(-ArrMonster[i].GetDir()); 
		}

		// 4. 그 후 한 줄 아래로 내린다 
		for (int i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Move({ 0, 1 }); 
		}
	}
}



void ShootingGame::GameUpdate() 
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// 캐릭터 위치에 글자를 하나 띄운다.
		NewPlayer.Render();
		Bullet::AllRender();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Render();
		}

		MonsterEndCheck();
		Collision();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Update();
		}

	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}