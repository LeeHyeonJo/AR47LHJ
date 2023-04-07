// 054_DeepCopyAndShallow Copy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 얕은 복사, 깊은 복사의 차이는 열혈 책 읽었음. 

#include <iostream>

class A
{
public:
    int* NewInt = nullptr;

    // 예시 1. Create 라는 멤.함을 써야하는 예시. 
    void Create()
    {
        NewInt = new int();
    }

    // 깊은 복사를 할 수 있도록 수정중. 참조할 메모리를 복새준다
    // 조건: null이 아니라면, 상대의 값을 그대로 복사(대입)한다. 
    void operator = (const A& _Other)
    {
        // 이걸 얕은 복사라고 하게 된다.
        // NewInt = _Other.NewInt;
        if (nullptr == _Other.NewInt)
        {
            //if (nullptr != NewInt)
            //{
            //    delete NewInt;
            //    NewInt = nullptr;
            //}
            return;
        }

        if (nullptr == NewInt)
        {
            // 딥카피의 준비를 한것.
            Create();
        }

        // 각자 참조할 메모리를 가질 수 있도록 복사/대입해준 상태임. 
        *NewInt = *_Other.NewInt;

        return;
    }


public:
    ~A()
    {
        if (nullptr != NewInt)
        {
            delete NewInt;
            NewInt = nullptr;
        }
    }
};

int main()
{
    {
        A NewInt0;
        A NewInt1;

        NewInt0.Create(); // 예시1. 0만 CREATe를 사용함. 

        NewInt0 = NewInt1; // 예시1. 할당안된 1이 0에 들어감. -> 0을 완전이 똑같히 만들어서 1에 넣은 후, 0을 지운다. 
                            // 0을 남기고 싶다면?? 상대의 new1이 null인 상태니까 그대로 리턴. 
    }

    //           100
    int* NewInt0 = new int();

    //           100
    int* NewInt1 = NewInt0;

    if (nullptr != NewInt0)
    {
        delete NewInt0;
        NewInt0 = nullptr;
    }

    // ???????? NewInt1

    if (nullptr != NewInt1)
    {
        delete NewInt0;
        NewInt0 = nullptr;
    }

    std::cout << "Hello World!\n";
}

