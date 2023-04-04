#include "Monster.h"
#include "ConsoleGameScreen.h"

Monster::Monster() 
{
	RenderChar = 'M';
}

void Monster::Update() 
{
	if (false == IsUpdate())
	{
		return;
	}

	if (true == DownCheck)
	{
		DownCheck = false;
		return;
	}

	Pos.X += Dir;
}