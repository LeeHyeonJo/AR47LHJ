

#include <iostream>
#include <conio.h>
#include <Windows.h>

class int2
{
public:
	int X = 0;
	int Y = 0;

public:
	int2 Half()
	{
		return { X / 2, Y / 2 };
	}

public:

	int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};

// 이게 1단계
// 근본오브 근본 수학 물리 
class ConsoleGameScreen
{
private:
	ConsoleGameScreen()
	{
	}

	static ConsoleGameScreen MainScreen;

public:
	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

public:
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static int2 GetScreenSize()
	{
		return int2{ ScreenXSize, ScreenYSize };
	}


	void ScreenClear()
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = 'a';
			}
		}
	}

	void ScreenPrint() const
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				// Arr[y][x] = 'b';
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}
	}

	bool IsScreenOver(const int2& _Pos) const
	{
		if (0 > _Pos.X)
		{
			return true;
		}

		if (0 > _Pos.Y)
		{
			return true;
		}

		if (ScreenXSize <= _Pos.X)
		{
			return true;
		}

		if (ScreenYSize <= _Pos.Y)
		{
			return true;
		}

		return false;
	}

	void SetScreenCharacter(const int2& _Pos, char _Ch)
	{
		if (true == IsScreenOver(_Pos))
		{
			return;
		}

		Arr[_Pos.Y][_Pos.X] = _Ch;
	}

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

};

ConsoleGameScreen ConsoleGameScreen::MainScreen;


/////////////////////////////////////////////////////////////////// 엔진

// 2단계 컨텐츠
// 클래스가 다른 클래스를 알아야 합니다.
class Player
{
public:
	Player()
	{

	}

	int2 GetPos() const
	{
		return Pos;
	}

	void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}

	void Input(ConsoleGameScreen& _Screen)
	{
		if (0 == _kbhit())
		{
			Sleep(InterFrame);
			return;
		}

		char Ch = _getch();

		int2 NextPos = { 0, 0 };

		switch (Ch)
		{
		case 'a':
		case 'A':
			NextPos = Pos;
			NextPos.X -= 1;
			if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
			{
				Pos.X -= 1;
			}
			break;
		case 'd':
		case 'D':
			NextPos = Pos;
			NextPos.X += 1;
			if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
			{
				Pos.X += 1;
			}
			break;
		case 'w':
		case 'W':
			NextPos = Pos;
			NextPos.Y -= 1;
			if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
			{
				Pos.Y -= 1;
			}
			break;
		case 's':
		case 'S':
			NextPos = Pos;
			NextPos.Y += 1;
			if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
			{
				Pos.Y += 1;
			}
			break;
		default:
			break;
		}

		Sleep(InterFrame);
	}


protected:

private:
	static const int InterFrame = 200;

	int2 Pos = int2(0, 0);
};


int main()
{
	Player NewPlayer = Player();

	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*');

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input(ConsoleGameScreen::GetMainScreen());

	}


}