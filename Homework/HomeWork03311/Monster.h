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
		Pos += _DeltaPos; // in2 Ŭ�������� += �����ڸ� operator�� ���� 
	}


private:
	int Dir = 1;
};
