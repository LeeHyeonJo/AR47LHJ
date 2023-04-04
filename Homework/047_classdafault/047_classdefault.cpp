// 046_defaultclass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.


#include <iostream>

class ADefaultClass
{
public:
    ADefaultClass(int Value) {} // 디폴트 생성자.
    ~ADefaultClass() {} // 디폴트 소멸자

    ADefaultClass& operator=(const ADefaultClass& _Other) = delete; // 디폴트 대입 연산자
    ADefaultClass& operator=(const ADefaultClass&& _Other) = delete; // 디폴트 대입 연산자
    ADefaultClass(const ADefaultClass& _Other) = delete; // 디폴트 복사 생성자
    ADefaultClass(const ADefaultClass&& _Other) = delete; // RValue 복사 생성자

protected:

private:

};