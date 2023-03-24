// 026_this.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 여기 다시 복습해다라고 해야지 

#include <iostream>


class player
{
public:
    player()
    {

    }

    void damage(/*player* const this*/ int att1)
    {
        // 주소값 끌어내는 법
        // __int64 address = (__int64)&hp;
        // 눈에 보이지 않지만 멤버함수에는
        // 첫번째 인자로 무조건 자기자신의 클래스 포인터가들어가게 됨. 

        hp -= att;

        // 어떻게 각 플레이어의 hp를 끌어내는것이 가능하지?
                // 우린 지금 this const의 값을 끌어내서 사용하고 잇기 때문. 
                // 
    

    }

    inline int gethp()
    {
        return hp;
    }

    inline int sethp(int value1)
    {
        hp = value1;

    }

    inline int getatt()
    {
        return att;
    }

    inline int setatt(int value2)
    {
        att = value2;
    }


protected:


public:
    int hp = 10;
    int att = 10;
};

// 포인터로 선언할때랑, int로 선언할때랑 메모리 흐름 차이 파악하기. 
// 진짜 중요함.. 

void gdamage(player* nplayer1, int att3)
{
    nplayer1->hp -= att3; // 클래스를 포인터로 사용할땐 값을 끌어오는건 . 에서 -> 으로 바뀜. 
    
//  [대미지: 300번지에 잇는 hp -=20을 하라는 의미 ]
//  [메인: 플레이어0(피통,공격) 300번지, 플레이어1(피통,공격) 400번지]
// 300번지에 있는 플레이어 0을 수정할 수 있게 되는 것. 

}

// 200번지에 새로운 플레이어를 만든다는 뜻 >0,1플레이어를 수정할수 없음!! 
void gdamage1(player nplayer1, int att)
{
    player.hp -= att; // 필기보고 코드 수정 이거 아님!!.찍고호출했음.

    //  [대미지: 200버지에 새로운 newplayer를 만든다  ]
    //  [메인: 플레이어0(피통,공격) 300번지, 플레이어1(피통,공격) 400번지]
    // 플레이어 0, 1 에는 아무런 영향도 주지 못함. 
    // 따라서 이때는 인트가 아니라, 참조형으로 플레이어를 불러와야함. 

}

int main()
{
    int value = 30;
    test(value); // test 함수 안 넣어서 일케 됨 

    player nplayer0 = player(); // v피통100
    player nplayer1 = player(); // 피통100


    // 300번지
    nplayer0.damage(/*newplayer0,*/20); // 결과 피통 80
                        // 멤버함수는 첫번쨰 인자로 무조건 자시자신의 클래스 포잉ㄴ터가 들어가게 됨 (this 떄문에)

    // 400번지
    //global
    nplayer1.damage(/*newplayer1,*/50); // 결과 피통 50 
                        // 멤버함수는 첫번쨰 인자로 무조건 자시자신의 클래스 포잉ㄴ터가 들어가게 됨 (this 떄문에)

    // 각 객체들이 어덯게 알아서 각자의 함수를 찾아서적용될 수 있었는가?
    // 메모리 내부에서 어떻게 흘러가는지 파악하기.

    //  [대미지:]
    //  [메인: 플레이어0(피통,공격), 플레이어1(피통,공격)]
};

