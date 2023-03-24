// 027_class오브젝트포인터.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 메모리 구조 잘 익히기. 아까 this에서 왜 ~ player0,1따로 찾아갈 수 있었는지 파악할 것(생략된것들) 
// this가null이되지 않게 주의. null이 왜 되는지 찾아보고 어디있는지 찾아보는 질문은ok. 

#include <iostream>

class player
{

public:
    void damage(/*player* const this*/)
        // 멤버 함수에 인수에는 항상 this 가 들어가있음. this 가 null이면 안됨. 

    {
        this->hp = 20;
        printf_s("맞았습니다")
    }
public:
    int hp = 100;
    int att = 10;
}

int main()
{
    int value = int();
    player nplayer = player();

    int* valueptr = nullptr;
    player* nplayer = &nplayer;

    valueptr = nullptr; // 널 가르킴
   // nplayer->damage(/*nplayerptr*/);
    // <- 이거는 출력 가능함. () 안의 값이 null이 아닌 상태라서
    // (위쪽에서 코드 짤때 그렇게 짠게 있음.) 
    // ㄴ 단순하게 값29를 넣은 아래 코드는null에 값 덮어씌우려고 해서
    // 그러나 함수로 선언한건 함수 내부 값이 null이 아니었기 때문. 

    // 널익셉션에 대해 알아두기 
    //  *valueptr = 20; (이거실행 안됨: null 가르키고있기 떄문) 

    // 
    //nplayer = nullptr;
    ///nplayer->hp=29; (null인데 값을 넣으려고 해서 안된거임) 





}

