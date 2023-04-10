#include "Bomb.h"

Bomb::Bomb() 
{
}

Bomb::~Bomb() 
{
}

void Bomb::Init()
{
	RenderChar = '@';
}

// explogen

void Bomb::Update() 
{
	ConsoleGameObject::Update();

	if (0 >= --BoomCount)
	{
		Off();
	}
}


void Bomb::Render() 
{
	ConsoleGameObject::Render();
}