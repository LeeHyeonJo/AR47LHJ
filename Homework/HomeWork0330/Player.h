#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen;
class Player
{
public:
	Player();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	void Input();

	void Render();

	void SetBulletArr(class Bullet* _BulletArr) //3.  Bullet �迭�� ���޹޾Ƽ� ����� �� �ֵ��� ����.
	{
		BulletArr = _BulletArr;
	}

protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);

	Bullet* BulletArr = nullptr; // 3.  �ʱ�ȭ


	// �̷� ������ Has a��� �Ѵ�. Player Has a Bullet
	// Bullet NewBullet; // �÷��̾��� ��ü ���ο� �Ѿ� �ѹ��� �ִ�.
	// Bullet* NewBullet; // �ٱ��� �ִ� �Ѿ��� �����Ҽ� �ִ�.
};

