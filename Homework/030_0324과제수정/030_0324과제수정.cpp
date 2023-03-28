// HomeWork0324.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 0327: 이 코드의 함수들을 class 선언으로 바꾸는 연습. 전역에 의존하지 않고 객체로 돌아갈 수 있도록 고쳐보는중임. 
// 모든 행동이 다 함수화가 되어있따는게 중요. 
// !!!!필기가 중간에 꼬였으므로 꼭 다시 보면서 차근차근 따라가보기!!!!

// 10단계까지가 wasd도 상하전우좌우 움직이기. 

#include <iostream>
#include <conio.h>
#include <Windows.h>

// 클래스 내부에 전역변수 선언하는 법 
// 
// 
// 전역 변수에 잇는 경우: 코드 영역에 존재하게 됨. 
//const int ScreenYSize = 3;
//const int ScreenXSize = 3;
//char Arr[ScreenYSize][ScreenXSize] = { 0, };
// 
// 컴파일러가 3줄을 이하처럼 바뀌어줌 
//char Arr[3][3] = { 0, };


// 4. 위치를 클래스로 생성
// ㄴ 이건 다 같이 돌려쓰는 것이므로 플레이어 클래스에서 그대로 사용할거임. 
// >>> 더 기초되는 개념이므로, 이것을 "1단계" 라고 한다. (ㅁㅁ을 구현하기 위해 필요한 기본개념) 

class int2 // 위ㅣ치임 
{
public:
	int x;
	int y;

public: // 이거 왜 나눈겆? > 아 스크린 중앙에 위치하게 하려고 
	int2 half()
	{
		return { x / 2,y / 2 };
	}

public: // 초기 위치 생성. 
	int2
};


class consolegamescreen  //1. 화면 띄워주는 클래스. (이쪽은 필기 복붙해서 쓰기) 
{
public:
	// 그러나 이렇게 내부에 있을땐, 전역에 있을때완 다른 메모리에 있게 됨
	// 스택에 있으므로, 어디에 있을지 알 수 없게 됨. 
	// >> 이 경우는 클래스 내부에 전역변수를 선언하는 ㅂ아법으로 감
	// >> 바로 앞에 static 을 붙이면 됨!! 
	const int ScreenYSize = 3;
	const int ScreenXSize = 3;

	//7.

	static int2 getscreenpos()
	{

	}

	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	void
};



//10. >> 여기서 화면 밖으로 나가지 않게 하려면
//결국 플레이어 클래스가 다른 클래스를 알게 되어야 함.  (여기까지가 0단계,엔진이 알아서 함) 

//  

//3. 플레이어 생성 중. 
class player
{
public:
	// 5. 여기에 위치 받는 클래스 재선언 getpos 
	int2 getpos() const // const 꼭 붙이기 : 위치 받는 함수 
	{
		return pos;
	}

	void setpos(value&) // 위치 수정하는 함수 

private:
	int2 pos; // 위에서 선언한 위치 클래스를 여기에 가져와서 씀. 

protected:

};


int main()

{

	consolegamescreen new;
	player nplayer;

	// 8. 

	int2 screensize = newscreen.getscreensize;


	const int ScreenYSize = 3;
	const int ScreenXSize = 3;

	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}

	// 정수를 정수로 나오면 실수는 버리고 정수의 값만 나옵니다.
	int PlayerY = ScreenYSize / 2;
	int PlayerX = ScreenXSize / 2;

	while (true)
	{

		// 콘솔게임스크린 new; 

		system("cls");

		// 2. 스크린클리어라는 클래스 선ㅅ언 후 사용 중. 

		Arr[PlayerY][PlayerX] = '*';

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}


		// 이건 내가 키를 눌렀다면 1
		// 아니라면 0을 리턴하는 함수고 정지하지 않습니다.
		// 키를 눌렀다는것을 체크해주는 함수
		if (0 == _kbhit())
		{
			// 0.5초간 멈춘다.
			Sleep(200);
			// 일부러 멈추게 만들겁니다.
			continue;
		}

		// 어떤키를 눌렀는지 알려주는 함수.
		char Ch = _getch();

		switch (Ch)
		{
		case 'a':
		case 'A':
			PlayerX -= 1;
			break;
		default:
			break;
		}

		Sleep(200);
	}

	// << 화면 밖에 못나가게>> 
	// 6. bool isscreenover (이건 화면 밖에 못 나가게 하는거 구현하는거임) 
	// 
	// 
	// 7. void setscreencharacter (이건 화면 밖에 못 나가게 하는거 구현하는거임2)
	// 레퍼런스 붙이는건 걍 습관임 (클래스는 8바이상일가능성이 높으니까)

	// 8인가 9인가
	// 상하전우좌우 움직이는것/getch 둘 다 클래스에 넣어서 줄이고 잇음 거기까지 구현함. 
}


// 0327 숙제: 클래스로 현재 상하전좌우 움직일 수 있게 되어있음
// 이 상태에서 consolescreen 클래스 내부의 기능을 player 클래스가 사용해서 
// 화면 밖으로 나가지 않게 구현해볼 것
// 조건: bool isscreenover를 반드시 사용할 것. 

// 클래스는 int와 동일. 즉 함수의 내부에 들어갈 수 있다는 뜻 // 함수(클래스) 이 식으로 