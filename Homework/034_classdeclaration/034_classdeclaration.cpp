// 037_classdeclaration.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 순환참조에 대하여 

#include <iostream>

//3. 클래스 전방 선언(함수 분리해준 다음) 
            // >> 전방선언으로 해결이 되는 경우, 안되는 경우가 있음. 구분해야함. 
            // 전자: 구현을 맨 아래쪽에 잘 해둠. 후자: 구현을 클래스 내부에 한 경우(예외존재)


class monster; // 이게 그거임. monster 클래스의 내용(몬스터의 크기, hp, 크기, 생성자)은 몰라도,
// 일단은 있다고 가정하고 쓰라는 뜻. 
class player
{
public:
    int att = 10;
    int hp = 100;

public:
    void attack(monster* monster1); // 나에게 접근한 대상을 때리는 함수.. 였는데!! (세미콜론빼고)
    /* {
        monster1->hp -= att; // 순환참조>> 모순이 발생하므로 어택만 아래쪽으로 빼줌
    }*/

    // 뺀 결과.. 그냥 attack 이라는게 싱ㅆ어, 알맹이가 없다는 뜻. 


    // 3-1) 전방선언해놓고, void attack(monster* monster1) {monster1->hp -= att;} 
    // 이렇게 내부에서 진짜로 구현을 채워두면 ~ 전방선언이 깨짐. 
}

class player; // player 클래스의 내용은 몰라도, 일단은 있다고 가정하고 쓰라는 뜻. 
// 이거, 
class monster
{
public:
    int att = 10;
    int hp = 100;

public:
    void attack(player* player1) // 나에게 접근한 대상을 때리는 함수 
        /*{
            player1->hp -= att; // 순환참조>> 모순이 발생하므로 어택만 아래쪽으로 빼줌
        }*/



        // 클래스 내부에서 구현을 해도 되는 경우: 해당 클래스의 내용(hp,크기.. )등을 참조하지 않아도 되는 함수의 경우

            // 예외1) = 몬스터의 8바이트 주소값을 받고, 외부로 8바이트의 주소값을 리턴하기만 하면 되는 함수.
            // 몬스터 내부의 멤버면수나 멤버함수를 사용하지 않았으므로 괜찮음. 

        monster* test(monster* nmonster)
    {
        return nmonster;
    }

    // >> 몬스터 내부의 내용을 몰라도 되는 함수면 전방선언으로 해결 가능 

        // 예외2) 이건 주소가 아니라 monster를 진짜로 넣어준 경우, 
       // 함수의 실행메모리(리턴값)를 정하려면 함수의 인자의크기를 알아야 함. 
        // >> 즉, monster의 크기를 알아야 한다는 뜻. >> monster의 크기는 멤버변수와 개수,종류로 결정됨
                // monster의 내용을 알아야 하므로 전방선언만으로 해결 불가능. 
    monster test2(monster nmonster)
    {
        return nmonster;
    }

}


int main()
{
    player nplayer;
    monster nmonster;

    nplayer.attack(nmonster);
    nmonster.attack(nplayer);

    nplayer.test(&nmonster);


}

void player::attack(monster* monster1) // 순환참조>> 모순이 발생하므로 어택만 아래쪽으로 빼줌 
{
    monster1->hp -= att;
}

void monster::attack(playerr* monster1) // 순환참조>> 모순이 발생하므로 어택만 아래쪽으로 빼줌  
{
    player1->hp -= att;
}
