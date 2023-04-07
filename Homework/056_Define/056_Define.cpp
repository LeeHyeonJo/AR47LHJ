// 056_Define.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <assert.h>

#define TEN 10

//Ten* Ten; //1. 디파인의 설명 
// 일케 선언시: PLUS(aaaa) //-> aaaa + aaaa 라는 괴상한 함수가 선언됨. 



// 함수형으로 사용하는 것
// 매크로함수라고 하는데 
// 매크로함수는 무조건 그냥 복붙입니다.
#define PLUS(Value1, Value2) Value1 + Value2
// #define PLUS(value1,value2) value1 + value2 >> 인자를 여러개 받는것도 가능함.  

#define MYTEST(Value1) Value1 = 0;

// 함수의 경우에는 일반적으로 형에 대한 검사나
// 자료형에 의한 컴파일 체크를 하지만
inline void Test(int _Value)
{
    _Value = 0;
    assert(false);
}

int main()
{
    int* Ptr;

    MYTEST(Ptr)

        // Test(Ptr);

        // 대부분 디파인 보다 인라인을 사용하라고 합니다.
        // _Value = 20;

        // PLUS("aaaaa");

        // "aaaaa" + "aaaaa";

        //int* Ptr;
        //Test(Ptr);

        TEN* TEN;
    // TEN * TEN
    // 10; * 

    std::cout << "Hello World!\n";
}

// inline과의 차이점. (함수내용을복붙) 
// inline은 컴파일러가 자료형을 인식해서 알아서 잘 바꿔줌. 
// ㄴ 함수의 경우는 일반적으로 형에 대한 검사나 자료형에의한 컴파일 체크를 해주기 때문 
// ㄴ 원하는 인자를 받을 수 있게 지정할 수 있음. 

// define은 그런거 없이 무식하게 복붙시켜줌. 
// ㄴ 그런거 안됨. 

// 얕게 알려준거임. 
