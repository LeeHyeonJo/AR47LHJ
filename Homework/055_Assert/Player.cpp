#include "Player.h"
#include "BaseHeader.h"


Player::Player()
{
}

Player::~Player()
{
}

void Player::Damage(int _Damage) // 대미지가 0인 상황에 에러가 뜨게 하고, 그 위치도 알고 싶음. 
{
	if (0 == _Damage)
	{ 
	 MsgBoxAssert("데미지가 0입니다");
	}
}




