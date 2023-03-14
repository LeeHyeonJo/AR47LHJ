// 002_TEST2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // f5 => 중단점이 존재하는 데까지 한번에 실행해라.
    // f10 => 처리형태가 구분되는 한 명령씩 실행하라 입니다.

    int Left = 7; // int = 자료형(정수 / 4바이트)
    int Right = 3;
    int Result = 0;

    // 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
    // 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴
    // 
    // 1. 단항연산자: 메모리 영역 1개 
    Result = -Left;// -7
    Result = +Left; // +7 >> 여기까지 실행하면 상단의 Result(-7) >> (+7)로 덧씌워짐. 

    // 2. 이항연산자: 메모리 영역 2개 * "산술연산자"가 대부분 여기에 속함. 
    Result = Right + Left; // 더하기 10 
    Result = Right - Left; // 빼기 4
    Result = Right * Left; // 곱하기 21
    Result = Left / Right; // 나누기 *정수의 나누기는 몫만 표기. R(작음)/L(큼)=0,  L(큼)/R(작음)=2
    Result = Right % Left; // 나머지 *R(작음:3)%L(큼:7)=3,  L(큼:7)%R(작음:3)=1

    // 전치, 후치는 나중에 
   
    // 3. 삼항연산자: 메모리 영역 3개 >> 안쓸거임 

    // *자료형(Data type) 2 -  bool(논리형)
    // 논리형이란? 참과 거짓이라는 2가지만 표현할수 있는 자료형.
    // true = 논리형 상수, 참 & false = 논리형 상수, 거짓 (의미 그대로)

    
    // 비교(관계) 연산자 ** 여기까지 했음!! 
    bool bResult = true; //beResult = 참이라는 의미
    bResult = false;

    bResult = Left == Right; // 같다
    bResult = Left != Right; // 같지 않다.
    bResult = Left < Right; // 작다
    bResult = Left > Right; // 크다
    bResult = Left <= Right; // 작거나 같다.
    bResult = Left >= Right; // 크거나 같다




    

}
