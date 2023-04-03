#pragma once

// ������� �� �����.
class int2
{
public:
	int x = 0;
	int y = 0;

public:
	inline int2 Half()
	{
		return { x / 2, y / 2 };
	}

	bool Check(const int2& _Other)
	{
		return x == _Other.x && y == _Other.y;
	}

	bool operator==(const int2& _Other) 
	{
		return x == _Other.x && y == _Other.y;
	}
	
	int2& operator+=(const int2& _Other) // int2�� += �����ڸ� ���� 
	{
		this->x += _Other.x;
		this->y += _Other.y;
		return *this;
	}

public:
	inline int2()
	{

	}

	// �����ڿ� 
	inline int2(int _x, int _y)
		: x(_x), y(_y)
	{

	}
};