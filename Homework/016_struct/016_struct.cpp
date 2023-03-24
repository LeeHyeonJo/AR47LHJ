// 016_struct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player; // 클래스 
{
    // 디폴트 접근 지정제한자가 private (이거이외에는 클래스와 동일합니더.) 
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

