#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject // monster Ŭ������ consolegameobject�� ���
{
public:
	Monster();
	void Update();

	void SetDir(int _Dir) { Dir = _Dir; } // monster ��ü�� ���� ���� **ConsoleGameObject�� ���, Pos�� ��� ������ ��ӹ��� 
	int GetDir() { return Dir; } // monster ��ü�� ������ ��ȯ **ConsoleGameObject�� ���, Pos�� ��� ������ ��ӹ��� 
	void Move(const int2& _DeltaPos)
	{
<<<<<<< HEAD
		Pos += _DeltaPos; // consolegamemath.h���� int2 Ŭ���� >  += �����ڸ� operator�� ���� 
=======
		Pos += _DeltaPos; // in2 Ŭ�������� += �����ڸ� operator�� ���� 
>>>>>>> 1689b31280f345ce19728bf65942e491118f5f2b
	}


private:
	int Dir = 1;
};
