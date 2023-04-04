#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	void Update();

private:
	int Dir = 1;
};

