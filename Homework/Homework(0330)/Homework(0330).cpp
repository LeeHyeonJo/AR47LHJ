// Homework(0330).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 0324 원본 파일은 그쪽 필터에 있음. 
/*0327: 0324숙제를 class로 구현할 것.
그 상태에서 consolescreen 클래스 내부의 기능을
player 클래스가 사용해서  player가 화면 밖으로
나가지 않게 구현해볼 것*/ 

#include <iostream>
#include <conio.h> 
#include <Windows.h> 


int main()
{
    //1. 게임 화면을 만든다. 
    const int screenysize = 5; 
    const int screenxsize = 5; 

    char map[screenysize][screenxsize] = {}; 

    // 1. 게임 화면을a로 가득 채운다. 
    for (int y = 0; y < screenysize; y++) 

    {
        for (int x = 0; x < screenysize; x++)     
           
        {
            map[y][x] = 'a';  
        }
    };

     

    for (int y = 0; y < screenysize; y++)
    {
        for (int x = 0; x < screenysize; x++)
            

        {
            printf_s("%c", map[y][x]);

        }
        printf_s("\n"); 

    }

    int playery = screenysize / 2;  
    int playerx = screenxsize / 2;  
    map[playery][playerx] = '*'; 
                    


    system("cls"); 

    for (int y = 0; y < screenysize; y++)
    {
        for (int x = 0; x < screenysize; x++)


        {
            printf_s("%c", map[y][x]);

        }
        printf_s("\n");

    }

    //// 여기까지 화면&플레이어 초기 위치 띄우기 ////

    

    while (true) 
    {
        
        map[playery][playerx] = 'a';
        system("cls");


        if (_kbhit()) 
        {
            char key = _getch();
             
            switch (key)  
            {
            case 'a': 

                
                if (playerx > 0) // 가로x 우측으로 이동 
                {
                    playerx -= 1;
                }
                break; 
                

            case 'd': 
            case 'D':
                if (playerx < screenxsize-1) // 가로x 좌측으로 이동 
                {
                    playerx += 1;
                }
                break;

            case 's': // 세로y가 상단으로 이동 
            case 'S':
                if (playery < screenysize-1) 
                {
                    playery += 1;
                }
                break;

            case 'w': // 세로y가 하단으로 이동 
            case 'W':
                if (playery > 0)
                {
                    playery -= 1;
                }
                break;


            } 

        } 

       

        map[playery][playerx] = '*'; 


        for (int y = 0; y < screenysize; y++)
        {
            for (int x = 0; x < screenysize; x++)


            {
                printf_s("%c", map[y][x]);

            }
            printf_s("\n");

        }

       
        Sleep(500); 

    }
};
