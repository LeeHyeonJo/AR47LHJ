// 035_functionoverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 헤더파일과 오버로드에 대해서 배울 것 
// 함수 오버로드 (함수 이름에 영향을 주는것: 1. 함수 이름 2. 함수의 자료형)

// 오버로딩에 대한 설명 끝 
#include <iostream>

// 1. 같은 이름의 함수 
// 그러나 위는 그냥 펑션, 아래는 펑션인트라는 함수로 봐야한다. 
// (함수 이름에 영향을 주는것: 1. 함수 이름 2. 함수의 자료형)
// 그러므로 함수 이름이 (노란게) 같아도 잘 돌아가는거임 
void function()
{
    printf_s("void function()\n");

}

void function(int a) // 펑션인트
{
    printf_s("void function(int a)\n");
} // 모호1

// 3. 모호하다는 스크립트: 컴파일러가 둘 중 무얼 호출해야하는지 모르는 경우 >> int short 어케 구분할거임 
void function(short a)
{
    printf_s("void function(short a)\n");
} // 모호2 



void function(int a, int b) // 펑션인트인트 
{
    printf_s("void function(int a, int b)\n");
}

void function(short a, int b) // 펑션숏인트 
{
    printf_s("void function(short a, int b)\n");
}

int main()
{
    int A = 'a'; // 
    int B = 'a'; // 이 두가지가 바로 암시적 형변환이 일어난 케이스(4) 


    function();
    function((short)10, 10)

        a na0 = a(10, 20);
}

// 2. 위와같은 이름의 규칙은 함수라고 이름붙은 모든것에 적용된다.
// 생성자(함수) 를 예시로 .. 
// a 클래스에서도 동일함. 메인 내부에 선언한 건 다시보기. 

class a
{
public:
    a()
    {

    }

public:
    a(int value1)
    {

    }

public:
    a(int value1, int value2)
    {

    }
};