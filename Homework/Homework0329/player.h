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

// �ƹ� Ű�� �Է� �� �Ѿ� 1�� // 
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

// �ذ���� //

protected:

private:
	static const int InterFrame = 200;

	bool Fire = false;

	int2 Pos = int2(0, 0);

};

