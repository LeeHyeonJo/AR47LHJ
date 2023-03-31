﻿// Homework(0330).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 0. 0324숙제: 봄버맨 게임 기본. 
// 화면(a)을 만들고 플레이어(*)를 띄운다. wsad에 반응해 상하좌우로 움직인다. 
// 조건1: *는 이동시 잔상을 남기지 않는다.
// 조건2: *은 화면을 넘어가지 않는다. 

#include <iostream>
#include <conio.h> // 이건 getchar() 때문에 
#include <Windows.h> // 이건 sleep()때문에 


int main()
{
 //1. 게임 화면을 만든다. 
    const int screenysize = 5; // 세로x2
    const int screenxsize = 5; // 가로x2 (이렇게 된 이유.. 외부for문이 세로y - 내부가 가로x라서) 

    char map[screenysize][screenxsize] = {}; // 그 다음 배열. 화면을 문자 a로 채울거니까 자료형은 char.
    // [] 안에는 상수가 들어가야 하는데, screenxsize는 상수가 아닌 변수이므로 들어갈 수 없음. 그래서 앞에 const를 붙여주게 된다. 
    // = {}; 배열 초기화임. 이거 반드시 해줘야 함. 

    // 

//2. 화면을 a로 가득 채워준다. 어떻게 넣어주지?? 
    // 외우셈: 배열의 모든 요소를 한 번에 동일한 값으로 초기화할땐 for를 사용하는것이 일반적임. 
    // 1. 인덱스를 활용해 각각의 공간에 접근해서 값을 넣어주는법. 해보자. 
    /*map[0][0] = 'a';
    map[0][1] = 'b';
    map[1][1] = 'c';
    map[1][0] = 'd';*/

    // 2. for문으로 가득 채우기. (이게 일반적) 

    for (int y = 0; y < screenysize; y++) // >> 외부 반복문
        // i가 screenxsize(상수)를 초과하면 멈추는 반복문.
        // 초기식: x = 0, 조건식: x < screenxsize(=screenxsize가 x보다 커지면 종료), 증감식: x++   
    {
        for (int x = 0; x < screenysize; x++)     // >> 내부 반복문 (내부 반복문은 외부 반복문이 한번 반복할때마다 새롭게 실행된다)
            // 주의: 각 반복문을 제어하는 변수는 달라야 한다 (ex. x,y)
        {
            map[y][x] = 'a'; // 이중for문 반복하면서 0이었던 배열을 0,0에서 시작해서 5,5까지a로 채워주는 과정 
        }
    }; 

//3. a로 가득 채운 화면을 출력해준다. 
    // 주의! 한번에 배열을 짠~하고 띄운다기보다는.. 
    // printf_s의 출력 원리를 생각하셈. 배열에 들어간 요소를 하나씩 일일히 띄워주는 함수였음. 
    // 그러니까 이번에는 for문을 사용해서 화면에 띄워줄거임. (이 부분이 어려움) 


    //4. 이제 플레이어를 만들거임. 필요한건 플레이어라는 존재와, 그가 있을 위치. 
    // 플레이어는 항상 맵의 정중앙에서 있게 시작할거임 -> 가로,세로를 절반한 값. 이걸 최초 위치로 사용할 것. 

   //4-1. 배열map에서 플레이어가 있을 위치를 지정한다. 
    int playery = screenysize / 2; // 세로 위치  >> 외부 어쩌구 
    int playerx = screenxsize / 2; // 가로 위치  >> 내부 어쩌구 

   //4-2. 플레이어의 위치에 플레이어(*)를 띄운다. >> 아래에서 구현하고 map 위에 뜰 수 있게 위치를 위로 옮김. 
     map[playery][playerx] = '*';

    for (int y = 0; y < screenysize; y++)
    {
        for (int x = 0; x < screenysize; x++) // 이중for문의 의미: x(가로)와 y(세로) 
            // 상수화된 변수 screensize의 값만큼..
            // 그러니까 레이저 인쇄처럼 한 행/열 씩 다다다다 인쇄해주는거임!!!. 
            // 그리고 이건 배열이 넣는 숫자에 따라서 바뀌니까 이렇게for문으로 배열을 구현할 수 밖에 없음!!  

        {
            printf_s("%c", map[y][x]); // 배열에a가 다 들어간 상태이므로. 문자형으로 배열에 들어간 a를 호출 
            /*9. %c : 하나의 문자로 출력 문자형
                 char c = 'a';
                 printf("%c", c);*/
        }
        printf_s("\n"); // (0,0) (1,0) (2,0) .... (4,4)까지 출력. 부등호인 이유는 0부터 시작하니까. 0~4면 다섯줄이지?

    }

    //// 여기까지 화면 띄우기 ////


    //5. wasd에 반응해서 플레이어가 움직이도록 한다. 
        // wasd를 눌렀을때, 라는 조건이 존재함. 키 입력 조건을 만족할"때마다" 1칸씩 움직여야함.
        // 이므로 if가 아니라 while을 써서 구현한다.(if는 조건이 만족되면 한 번만 실행 - while은 조건만족시 여러번실행) 
        // 키 입력은  키를 눌렀을 때만 화면이 멈추도록 해주는 함수가 있다. -> _kbhit()
        // 키를 눌렀다면 1 트루, 아니라면 0 펄스을 리턴하는 함수이고 정지하지 않는다. - 으로 구현한다. 

    while (true) // 키를 눌렀을때. 
    {
        //system("cls");

        // ?? 플레이어가 지나간 자리를 다시map으로 변경한다. 
        // map[playery][playerx] = 'a';


        // 5-1.우선 키가 눌렸을때를 if로 구현. 
        if (_kbhit())
            // 조건식으로는 _kbhit() - 키 누르면 0 이 아닌 값을 "버퍼"로 저장, 아니면 0 - 사용.
            // 버퍼란? 화면에 출력되기 전까지 임시적으로 입력한 값을 저장하는 메모리 공간. 
            // 버퍼에 입력된 키값을 _getch()로 받아야 한다. : 그냥 사용법이 이럼 외우셈. 
                //_getch()는 콘솔에서 "단일문자" ( = _kbhit()  에서 반환된, 사용자가 누른 키 값) 을 받음 
                // 요약: 사용자가 누른 키값을 getch()가 "한 글자" 읽어준 후 int로 반환해준다. 
        {
            char key = _getch();
            // wasd - 단일문자를 입력, 버퍼로 받아줄 것이므로 자료형은 char. 

        //5-2. wasd 눌릴때를 구현
            // >> 제어식의 결과에 따라 여러 경로중 하나를 선택할 수 있으므로 스위치문 사용. 
            switch (key) // *그냥 _getch();를 넣는 건 안되나 
            {
            case 'a': // 가로x가 좌측으로 이동 
            case 'A': // 대소문자 둘다 OK. case는 여러개 걸어줄 수 있음. 
                playerx -= 1;
                break;

            case 'd': // 가로x가 우측으로 이동 
            case 'D':
                playerx += 1;
                break;

            case 's': // 세로y가 하단으로 이동 
            case 'S':
                playery -= 1;//*내려가니까 -아님?? 
                break;

            case 'w': // 세로y가 하단으로 이동 
            case 'W':
                playery += 1;//*올라가니까 +아님??
                break;
            }

        }
        // 화면에 플레이어 띄우는 것까지 진행. 이제 wasd 움직이게 해야 함. 


           
    }
        






};