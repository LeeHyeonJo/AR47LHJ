#pragma once

// 헤더에만 다 만든다.
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
	
	int2& operator+=(const int2& _Other) // int2에 += 연산자를 구현 
	{
		this->x += _Other.x;
		this->y += _Other.y;
		return *this;
	}

public:
	inline int2()
	{

	}

	// 생성자에 
	inline int2(int _x, int _y)
		: x(_x), y(_y)
	{

	}
};