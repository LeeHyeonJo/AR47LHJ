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

	void SetBulletArr(class Bullet* _BulletArr) //3.  Bullet 배열을 전달받아서 사용할 수 있도록 수정.
	{
		BulletArr = _BulletArr;
	}

protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);

	Bullet* BulletArr = nullptr; // 3.  초기화


	// 이런 구조를 Has a라고 한다. Player Has a Bullet
	// Bullet NewBullet; // 플레이어의 신체 내부에 총알 한발이 있다.
	// Bullet* NewBullet; // 바깥에 있는 총알을 조작할수 있다.
};

