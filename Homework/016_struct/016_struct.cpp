// 016_struct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player; // 클래스 
{
    // 디폴트 접근 지정제한자가 private
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int speed = 3;
}


struct monster; // 스트럭트: 
{
    // 디폴트 접근 지정제한자가 public
    int Att = 10;
    int Def = 2;
    int Hp = 100;
    int speed = 3;
}

int main()
{
    Player nPlayer = Player(); // 3.뉴 플레이어를 하나 만든 후, 클래스에 정의한 걸 가져옴. 

    nPlayer. // .을 찍어서 클래스 내부의 멤버변수에 접근할 수 있음// - 이거 잘 들어간거 다시 확인해보기. 

}


// 0321 숙제 // 

// 1. 38class : 그대로 실행해보면, 때린 순간 스테이터스가 변동(!!!)되도록 코드를 바꿔오기.
// system("cls"): 콘솔 화면에 있는걸 다 지우는 명령어 이걸 활용할 것. 
// 실시간 대미지 반영!!  
// 실행해보면 플레이어 - 몬스터 공격 후 피통이 동시에 까임.
// 플레이어 공격 > 몬스터 hp 감소 > 몬스터 공격 > 플레이어 hp 감소 이렇게 반영되도록 변경할 것. 
