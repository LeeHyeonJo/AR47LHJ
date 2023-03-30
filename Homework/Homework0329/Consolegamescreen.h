#pragma once
#include "Consolegamemath.h"

// �̰� 1�ܰ�
// �ٺ����� �ٺ� ���� ���� 
class Consolegamescreen
{
public:
	// Ŭ���� ���ο� ���������� �����Ҽ��� �ֽ��ϴ�.
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static Consolegamescreen& GetMainScreen()
	{
		return MainScreen;
	}

	static int2 GetScreenSize();

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

protected:

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	Consolegamescreen();
	static Consolegamescreen MainScreen;
};
