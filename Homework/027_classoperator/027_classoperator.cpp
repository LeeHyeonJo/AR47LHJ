// 027_classoperator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 오늘의 과제: class 내부에서 스코프 열고 구현할 수 있는 연산자 전부 해보기
// 원래 연산자와 똑같이 작용할 필요는 없음. 되는지, 안되는지 직접 테스트 해볼 것. 
// 오늘 이해도 절반은 넘은듯 

#include <iostream>

class number
{

public:
    int value;

public: // 멤버 이니셜라이저로 선언해보기 
    number(int value1)
        : value(1)
    {
    
    
    }

         
    int operator+(int value1) // 클래스가 연산자를 사용할 수 있게 만드는 기능을 직접 추가.
                              // 예시로 이건 더하기  
    {
        return value + value1;
    }

    void ddd()
    {
            // 이 넘버 클래스 내부에서 
            // 자신이 논리적으로, 이 연산자를 어떻게 구현할 수 있겠다 하는 것을 전부 만들어볼 것
            // (논리,산술,비교,관계 등) 구현해보기 
            // 이론적으로는 형식만 맞춘다면 모든 연산자를 구현할 수 있음. 
            // 에러가 나는 경우도 분명히있을 수 있음. 그러나 빌드는 되어야 함. 
    }

};

int main()
{
    number newnumber = 10;


    // 겹지정 연산자 
    newnumber + 10;
    newnumber.operator+(10);
    number value = 10;
}; 

