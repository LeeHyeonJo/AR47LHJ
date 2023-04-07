#include "ConsoleGameScreen.h"
#include <iostream>

// 0407: 화면을 늘이고, 줄일거임
// 그러므로 정적할당된 스크린arr을 동적할당해줄거임. 
// arr > arrsreen으로 변경 // ConsoleGameScreen 아마 이거 헤더에서 바꺼줄거임 
// 그 다음, 스크린 사이즈를 받앙줄 함수가 필요함. 셋 스크린 사이즈를 넣음. //3

ConsoleGameScreen ConsoleGameScreen::MainScreen;

// delete는 역순이어야 함. 그림을 그리며 이해할 것.  //4 -> 이제 게임엔진 디버그 h로 이돔. 
// 뭘 복붙해왔더라 헐. 이건 나 오기 전에 친듯?? 

// 소멸자 쳐줄거임. 
ConsoleGameScreen::~ConsoleGameScreen()
{

}

void ConsoleGameScreen::SetScreenSize(int2 _Size) //3
{
	Size = _Size  // 이 함수의 작동원리 스택과 힙의 도식 직접 그려보면서 이해하기(여기에 있는 건 전부 스택영역에 있는 포인터. 실제로 쓰는건 데이터 영역에 있는 데이터들)  
					// 내가 사용할 실제 메모리 (ConsoleGameScreen,SetScreenSize,arrsize) 
		Arrscreen = new char* [Size.Y]; 

	for (size_t i = 0; i < Size.Y; i++)
	{

		ArrScreen[i] = new char[Size.X]; //[3,3]으로 사이즈를 정의한 경우. >> char*x3 배열 3개를 스택의 new char* 3개가 하나씩 가리킴. 

		// delete 할때 순서는 역순이어야 함. // 이제 이거 딜리트할거임. 
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
	for (size_t y = 0; y < ScreenYSize; y++) // this->Size.Y (정적에서 동적으로 변경, 여기는 전부 포인터로 바뀜. this는 모함수의 냉ㅇ물을 의미) 
	{
		for (size_t x = 0; x < ScreenXSize; x++) // this->Size.X
		{
			// Arr[y][x] = 'b';
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
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
	return int2{ ScreenXSize, ScreenYSize }; //Size 리턴으로 변경 
}