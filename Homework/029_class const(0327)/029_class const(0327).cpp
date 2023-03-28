// 028_class const(0327).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class player
{
public:

    // 3. void sethp(int value) = 이건 const xxx // sethp = 바뀌어야 하는 피통이니까. 

    int gethp() const //2. 여기에 hp가 어떠한 값인지 알려주는 함수를 넣었음 (이걸 겟함수라고 함) 
        // 이때, hp값은 바뀌면 안되니까 무조건 const를 붙임
        // ㄴ 즉, 최우선으로 const를 붙이면서 만들기 (함수 내부에서 바뀌지 않는 멤버변수)
        // ㄴ 바뀌어야 하는 값이라면 (바뀌어야할 멤버변수) 그때  const를 떼는거임 
// 이 함수를 호출해도 클래스 플레이어의 hp에 변화가 없다는 의미임. 멤버함수의 const 함수가 있는 이유!!! 

    {
        return hp;
    }
    // 1. 멤버함수 뒤에는 const를 붙일 수 있다. 
    // 의미: 이 함수를 호출한다 해도, 이 클래스를 통해 만들어진 객체는 변화하지 않음
    // (= 호출할때마다 피통 바뀌는 일없음)
    void printstatus(/*player* const this 가 항상 디폴트*/) const
    {        // const 를 붙인 순간 att에 붉은 줄이 감
            // this->att += 100; 로 이해해야 함. 
        this;
        att += 100;

        printf_s("플레이어의 능력치------------------\n");
        printf_s("공격력: %d\n", att);
        printf_s("공격력: %d\n", hp);
        printf_s("플레이어의 능력치를 출력.\n");
    }

protected:

private:
    int hp = 100;
    int att = 20;
};

int main()
{
    player nplayer = player();
    nplayer.printstatus();
    nplayer.printstatus();
    nplayer.printstatus();
    nplayer.printstatus();

}

