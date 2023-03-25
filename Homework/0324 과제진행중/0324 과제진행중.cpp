// 0324 과제.cpp : 일단 과제 코드 보면서 따라쳐보기. 
// 숙제 0: 우선 상하좌우로 다 움직이게 만들어보기. 
// 숙제 1: 코드 그대로 출력시 ***이 나옴. 이 잔상을 지워보셈 *(플레이어)이 홀로 움직여야함. 
// 숙제 2: 좌측으로만 움직였는데 ~~ 위로도 **가 뻗어나감. 이걸 막아보셈. (= 화면 밖으로 나가지 못하게) 
			/// 내가 키를 눌렀을 때만! 멈추게 만들어주는 함수가 있음. 

// 선택과정: (이건 질문해도 안 받음)
// 숙제 3: 장애물 만들고 배치하기. 플레이어는 그 장소로 이동 불가능.
// 숙제 4: f를 누르면 폭탄이 설치됨. 눈에 보여야함. 
// 숙제 5: 일정시간이 지나고 폭탄이 터지면서 - 십자가로 @모양이 출력되도록 할 것. 
// 이때 터지는 모양에는 딜레이가 있어야 함. 

// 코드는 개 무식하게 쳐보기 

#include <iostream>
#include <conio.h>
#include <Windows.h> // 슬립 쓰려고 


int main()
{
	const int ScreenYSize = 3;
	const int ScreenXSize = 3; // 여기는 모니터 만들고 있는거임. 배열을 활용해서 그 갯수만큼 a만들어줌. 

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
		system("cls");

		Arr[PlayerY][PlayerX] = '*';

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}

		// 이건 내가 키를 누르면 1, 아니라면 0을 리턴하는 함수. 정지하지 않음. 
        // 키의 누름 여부를 체크.
		if (0 == _kbhit())
		{
			// 허나 이 상태로는 겁나 깜빡거려서 눈이 아프므로.. 멈추게 하는 함수도 넣어줄거임. (sleep)
			// 0.5초간 멈춘다.
			Sleep(200);
			// 일부러 멈추게 만들겁니다.
			continue;
		}

		// 어떤키를 눌렀는지 알려주는 함수. -> 따라서 _getch(); 는 "어떤 키" 를 입력받았는지 체크해주는 함수라고도 볼 수 잇음. 
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

