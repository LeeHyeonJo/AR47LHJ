#pragma once
#include "ConsoleGameMath.h"
#include "GameEngineArray.h"

// 이게 1단계
// 근본오브 근본 수학 물리 
class ConsoleGameScreen
{
public:
	// 클래스 내부에 전역변수를 선언할수가 있습니다.
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	static int2 GetScreenSize(); // static 떼고  
	//{
		//return MainScreen.GetScreenSize(); //한번 더 정의해주는건데 좋은 상황은 아닌ㅁ 
	//}

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

protected:

private:
	// char Arr[ScreenYSize][ScreenXSize] = { 0, };

	// 8. 이것이 본질적이 무엇과 같은지 코드 참고
	// 대풍 무언가의 포인터라는 건 이해함. 

	// 여기 중요함!!!!!!!!!!! class GameEngineArray 내부에 잇는 기능을 이해하기. 
	// 
	// char** ArrScreen = nullptr; // 이것과 아래가 같은 코드라는 걸 이해할 것. 그런데 차이가 있음. 얘는 모든 기능(ex. delete)을 다 쳐주야 함. 

	GameEngineArray<GameEngineArray<char>> ArrScreen; // 6. 이걸 사용하면 delete를 사용하지 않아도 되게 됨. 이미 소멸자에서 구현해두었기 때문. cpp로 이동. 

	// 위 코드는 clas GameEngineArray로 구현한것이고, 모든 기능을 그안에 담고있으므로 위 코드보다 훨씬 쓰기 편함. 


	ConsoleGameScreen();

	// 싱글톤 패턴이라고 합니다.

	static ConsoleGameScreen MainScreen;
};