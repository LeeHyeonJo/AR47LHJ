#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];


void Bullet::AllRender() // 1. �Ѿ� �迭 ��ü�� ������ 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (ArrBullet[i].IsFire())
		{
			ArrBullet[i].Render();
		}

	}

}

void Bullet::AllUpdate() // 2. �Ѿ� �迭 ��ü�� ������Ʈ 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (ArrBullet[i].IsFire())
		{
			ArrBullet[i].Update();
		}
	}
}

Bullet::Bullet()
{

}

void Bullet::Render()
{
	if (true == Fire)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '^');
	}
}

void Bullet::Update()
{
	if (true == Fire)
	{
		--Pos.Y;
	}
}