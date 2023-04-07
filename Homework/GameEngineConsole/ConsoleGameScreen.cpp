#include "ConsoleGameScreen.h"
#include <iostream>

// 0407: ȭ���� ���̰�, ���ϰ���
// �׷��Ƿ� �����Ҵ�� ��ũ��arr�� �����Ҵ����ٰ���. 
// arr > arrsreen���� ���� // ConsoleGameScreen �Ƹ� �̰� ������� �ٲ��ٰ��� 
// �� ����, ��ũ�� ����� �޾��� �Լ��� �ʿ���. �� ��ũ�� ����� ����. //3

ConsoleGameScreen ConsoleGameScreen::MainScreen;

// delete�� �����̾�� ��. �׸��� �׸��� ������ ��.  //4 -> ���� ���ӿ��� ����� h�� �̵�. 
// �� �����ؿԴ��� ��. �̰� �� ���� ���� ģ��?? 

// �Ҹ��� ���ٰ���. 
ConsoleGameScreen::~ConsoleGameScreen()
{

}

void ConsoleGameScreen::SetScreenSize(int2 _Size) //3
{
	Size = _Size  // �� �Լ��� �۵����� ���ð� ���� ���� ���� �׷����鼭 �����ϱ�(���⿡ �ִ� �� ���� ���ÿ����� �ִ� ������. ������ ���°� ������ ������ �ִ� �����͵�)  
					// ���� ����� ���� �޸� (ConsoleGameScreen,SetScreenSize,arrsize) 
		Arrscreen = new char* [Size.Y]; 

	for (size_t i = 0; i < Size.Y; i++)
	{

		ArrScreen[i] = new char[Size.X]; //[3,3]���� ����� ������ ���. >> char*x3 �迭 3���� ������ new char* 3���� �ϳ��� ����Ŵ. 

		// delete �Ҷ� ������ �����̾�� ��. // ���� �̰� ����Ʈ�Ұ���. 
	}

}


void ConsoleGameScreen::ScreenClear()
{
	system("cls");

	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{
	for (size_t y = 0; y < ScreenYSize; y++) // this->Size.Y (�������� �������� ����, ����� ���� �����ͷ� �ٲ�. this�� ���Լ��� �ä����� �ǹ�) 
	{
		for (size_t x = 0; x < ScreenXSize; x++) // this->Size.X
		{
			// Arr[y][x] = 'b';
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

// �̳༮�� ������ ����ؼ� �÷��̾ �ٱ����� �������� ���弼��.
bool ConsoleGameScreen::IsScreenOver(const int2& _Pos) const
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

void ConsoleGameScreen::SetScreenCharacter(const int2& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	Arr[_Pos.Y][_Pos.X] = _Ch;
}



ConsoleGameScreen::ConsoleGameScreen()
{
}

int2 ConsoleGameScreen::GetScreenSize()
{
	return int2{ ScreenXSize, ScreenYSize }; //Size �������� ���� 
}