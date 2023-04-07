#include "ShootingGame.h"

#include <iostream>

// ���� ����� ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// ������ �����ϱ� ���� �غ��Ѵ�.
	// �Ѿ��� ������ ������ ���弼��.

	// �����ϸ� ������ ��� �Ѿ��� �߻���� �ʾ������̹Ƿ� �� ����.
	Bullet::AllOff();

	// �÷��̾ �Ѿ��� �����͸� �˰� �Ѵ�.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// �÷��̾ ȭ���� �߾ӿ� ��ġ��Ų��.
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

	// ��� �Ѿ˰�
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

//0331 ����: monster�� ������ �����ϱ�.  


void ShootingGame::MonsterEndCheck() 
{
	int2 leftMostMonsterPos = ArrMonster[0].GetPos();  // ���� ������ ���� 
	int2 rightMostMonsterPos = ArrMonster[ArrMonsterCount - 1].GetPos(); // ���� �������� ���� 

	// 1. ������ ������
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].Move({ 1 * ArrMonster[i].GetDir(), 0 }); // Monster::Move()�� Monster.h�� �ۼ�. 
	}

	// 2. ���� �� ���� ���� ���� ������ ���� ��ġ�� üũ
	if (leftMostMonsterPos.x <= 1 || rightMostMonsterPos.x >= ConsoleGameScreen::GetMainScreen().GetScreenSize().x - 2)
	{
		// 3. ���� ��Ҵٸ�, ������ �ٲ۴� 
		for (int i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].SetDir(-ArrMonster[i].GetDir()); 
		}

		// 4. �� �� �� �� �Ʒ��� ������ 
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

		// ĳ���� ��ġ�� ���ڸ� �ϳ� ����.
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