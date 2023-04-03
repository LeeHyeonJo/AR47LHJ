#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject // monster 클래스가 consolegameobject를 상속
{
public:
	Monster();
	void Update();

	void SetDir(int _Dir) { Dir = _Dir; } // monster 객체의 방향 설정 **ConsoleGameObject을 상속, Pos의 멤버 변수를 상속받음 
	int GetDir() { return Dir; } // monster 객체의 방향을 반환 **ConsoleGameObject을 상속, Pos의 멤버 변수를 상속받음 
	void Move(const int2& _DeltaPos)
	{
		Pos += _DeltaPos; // in2 클래스에서 += 연산자를 operator로 정의 
	}


private:
	int Dir = 1;
};
