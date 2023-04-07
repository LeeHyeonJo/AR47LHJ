// 057_classnew.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// class도 동적할 당 할 수 있을까? > 가능. class 내부에서 new자체를 품고 들어갈 수 있음. 
// 배열을 맏느는 클래스, 그 클래스의 오브젝트를 배열선언하면 10개 플레이어 만드는 기능을 <- 10개 만들 수 잇게 됨. 
// ㄴ 이 개ㅕㄴㅁ이 콘솔게임스크린 헤더로 이어지 

#include <iostream>

class Test // 캐릭터를 배열로 만드는 기능 
{
    char* ArrChar;
public:
    void Resize(size_t Size)
    {
    // 내부 코드 채우기 
    
    }


};

int main()
{
    char* Arrint = new char();

    delete Arrint;
    // 이것을 만든 것 자체가 char의 배열을 만든것과 동일 

    Test* ArrTEst = new Test();
    
    delete ArrTest; 
}

