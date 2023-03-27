// 0324 과제 
// 0. wasd키로 상하좌우 이동 1. *의 잔상을 남기지 않을 것 2. 화면을 넘어가지 않게 구현할 것 
// 0,1번까지 해결. 
// 해결 방식: 이동시 이전 위치의 문자를 지우고 새로운 위치에 *를 재출력 & *이 지나간 위치를 a 문자로 변경 

#include <iostream> 
#include <conio.h> 
#include <Windows.h> 


int main()
{
	const int ScreenYSize = 3;
	const int ScreenXSize = 3;

	char Arr[ScreenYSize][ScreenXSize] = {}; // 배열 초기화 

	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}


	int PlayerY = ScreenYSize / 2;
	int PlayerX = ScreenXSize / 2;

	while (true)
	{
		system("cls");

		// 이전 위치를 a로 변경
		Arr[PlayerY][PlayerX] = 'a';

		if (_kbhit())
		{
			char Ch = _getch();

			switch (Ch)
			{
			case 'a':
			case 'A':
				PlayerX -= 1;
				break;
			case 'd':
			case 'D':
				PlayerX += 1;
				break;
			case 'w':
			case 'W':
				PlayerY -= 1;
				break;
			case 's':
			case 'S':
				PlayerY += 1;
				break;
			default:
				break;
			}
		}

		// 새로운 위치를 * 문자로 변경
		Arr[PlayerY][PlayerX] = '*';

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}

		Sleep(200);
	}
}