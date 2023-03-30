#pragma once
#include "Consolegamemath.h"

class Consolegamescreen;
class player
{
public:
	player();

	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	inline int2 GetPos() const
	{
		return Pos;
	}

	void Input();

// 아무 키나 입력 시 총알 1발 // 
	inline bool IsFire()
	{
		return fire;
	}

	bool fire = false;

	void shoot() {
		if (fire) {
			//????
		}

	}

// 해결못함 //

protected:

private:
	static const int InterFrame = 200;

	bool Fire = false;

	int2 Pos = int2(0, 0);

};

