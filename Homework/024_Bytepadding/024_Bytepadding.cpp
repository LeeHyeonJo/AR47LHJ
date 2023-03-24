﻿// 024_Bytepadding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 

#include <iostream>

class player // 내가 디자인하는 나만의 자료형

    // 주솟값 확인해보셈: 어떻게? - 포인터 활용해서  address 하는법 체크해보기. 모르겠으면 물어봐!!
    // 오늘의 숙제: 
    
{
public:
    int att;
    int def;
    // __int64 value3; >> main안에서 att 4byte, def 4byte, 남은거는 value3이 가져감 8바이트

    int att1; // 4바
    short def2;// 2바 (att1에 8바 할당, 남은 바이트에 short 들어갈 수 있으므로 그대로. 그 다음 aaa는 8바이트이므로 그대로 8바 추가) 
    __int64 aaa; //8바
    // >> 이건 총합 16(괄호처럼 계산해서 16바이트) 


    // 바이트 패딩 하는 법 
    // 1. 8바이트 이하 가장 큰 바이트의 자료형을 찾는다. (예시에서 int)
    // 2. 위에서부터 하나씩 넣어가며 계산.
    // 3. 빈 곳에 들어가면 그대로 패스. 
    // 근데 이때 ... [8바:att1, def2][8qk:aaa]: 16바이트 이렇게 메모리에 들어갈 때, 
    // def2는 att1에 딱 붙어있는가? 아니면 8바 뒤쪽에 붙어잇는가? <- 이걸 주소값을 통해 확인하라는 뜻 
    // 이때 비어있는 메모리를 "바이트 패딩" 현상이라고 한다. 

    // ㅁㅁ 1ㅁ2ㅁ  1,2중 어느쪽에 붙어있는지. 
};

int main()
{
    int size = sizeof(player);

    // int& Ptr = &nplayer; // 포인터 활용해서 주솟값 확인해보라는 뜻. 
    printf_s("%d", size); // size 크기는 4 
                                    // 크기는 16
}

// 구글 시트 두번째 질문
//범위 확인 연산자(::) 와 멤버 선택 연산자(.) 의 차이점이 궁금합니다.
//그리고 이런 방식으로 썼을때 왜 이런 오류가 나는지 궁금합니다.

// 300번지의 플레이어를 대표하는 뉴 플레이어 
// Player Newplayer; (풀네임은 뉴플레이어.플레이어::hp;)
// -> 메모리적으로 스텍에서 Player가 생성되고, 그것이 newplayer로 바뀌는 것

// 일반적인 멤버 변수 는 :: 를 통해서 사용할 순 없다 
// player::Hp; <= 멤버변수일 경우 아무런 의미도 없다. 

// 뉴플레이어.플레이어::hp; 이렇게는 사용가능 그러나 잘 안씀~
// (뉴 플레이어가 가진 플레이어의 HP) <- 일일히 클래스 이름 선언해야하는거번거롭기 때문 

// 그래서 보통은 뉴플레이어.hp; 이렇게 쓰고 끝남. 