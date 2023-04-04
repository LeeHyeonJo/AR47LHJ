// 049_Vptr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 가상함수와 함수 포인터. 
// 오버라이드는 이해했는데 함수 포인터가 섞인 부분을 이해 못함. 
// ㄴ 가상함수의 원리...에서 컴파일러가 알아서 이중포인터로 함수포인터 쓰는 파트. 여기 다시 물어보기. 

#include <iostream>

// virtual이 붙어있는 클래스가 존재한다면
// 이 클래스의 객체가 생성될때.
// void(*__vfptr[???])() <= 가상함수 테이블이라고 합니다.
// 
// 함수포인터의 배열을 만들어내고 그걸 함수포인터의 포인터로 저장합니다.
// void(**__vfptr)()

class FightUnit
{
public:
    virtual void Damage() // 멤버함수를 가상함수화 (virtual을 멤버 함수 앞에 붙여서 사용) 
        // 가상함수로 사용: 부모의 멤.함을 자식껄로 쓸 수 잇게 됨. (Player:: 이렇게)  
        // 가상함수로 사용하지 않음: 부모의 멤.함은 여전히 부모의 것. (FightUnit:: 이렇게) <- 일어나서 확인해보기 
    {

    }

    virtual void FightStatusRender()   // 가상함수가 2개여도 플레이어의 크기는 8. 
    {

    }

    // 왜 플레이어의 크기는 여전히 8인가? (이중포인터(함수 포인터)와 연관있음) 

    // virtual 이 붙어있는 클래스가 존재한다면, 클래스의 객체가 생성될때 
    // 

public:
    FightUnit()
        // [0]FightUnit::Damage
        // [1]FightUnit::FightStatusRender 
    {
        this;
        // 여기에서 가상함수 테이블을 확인할 수 있음. 
        // 당연하게도 FightUnit 에 속한 멤버함수 2개가 호출됨. 
        int a = 0;
    }
};

class Player : public FightUnit // Player가 FightUnit를 상속 
{
public:
    void Damage() override  // ovverride는 생략 가능. 그냥 표시해준거임. 
    { // 오버라이딩: 가상함수를 파생 클래스에서 재정의하는 것을 의미. 
        // Damage 가상함수는 FightUnit의 파생 클래스 Player에서 재정의 되었다. 라는 뜻. 
        // 재정의 시, 파생 클래스 쪽의 멤버함수가 우선시된다. 

    }

    void FightStatusRender() override 
    {

    }

public:
    Player()
        // [0]Player::Damage
        // [1]Player::FightStatusRender
            // =  부모 클래스의 멤.함 damage,스테이터스렌더가 전부 "가상함수"이므로  player것 처럼 사용할 수 있음
            // 부모의 것인 채로 사용하고 싶다면, 가상함수를 해제하면 됨. <- 아침에 확인해보기. 
    {
        this; // 마찬가지로 여기에 중단점 걸어서 가상함수 테이블 확인해보기.  

            int a = 0;
    }
};



// 클래스를 하나 더 만들어서 상속 더 내려보기 //

/*class Fighter : public Player // 파이트 유닛(여기서 오버라이드 2개) > 플레이어 > 파이터  
{
    // public: 
    // fighter(); 생성자가 먼저 만들어지고 
    // { 가상함수 테이블에 뭐가 채워지는지 알려줄게 
    // [0]FightUnit :: Damage
    // [1]FightUnit :: FightStatusRender
    //   엄마클래스 - 파이트 유닛에서부터 둘 다 오버라이드가 걸려있으니 주르륵~내려오는것. 
    // }
};*/

int main()
{
    int Value = sizeof(Player); // 함수 내부에 아무것도 존재하짐 않으면 그 크기는 1. 

    Player NewPlayer;

}
