// 과제: 실시간으로 스테이터스가 변동하는 것을 출력하는 인간-몬스터 공격 프로그램 
// 해결방식: 이전 체력을 저장하는 변수를 만들고 출력 

#include <iostream>
#include <conio.h> // _getch() 를 사용
#include <stdlib.h> // system("cls") 사용

// damage 함수를 수정. att에 의한 hp 변경을 main 으로 이동 
void damage_print(
    const char* const attname, // 공격하는 캐릭터 이름 
    const char* const defname, // 공격당하는 캐릭터 이름 
    const int& att //공격자의 공격력
)
{
    printf_s("%s의 옆구리 찌르기!\n", attname); 
    printf_s("%s은(는) %d의 대미지를 입었다!\n", defname, att);

}


void status_print(
    const char* const attname, //공격자의 이름 
    const int& att, // 공격자의 공격력
    int& hp // 공격당할때 체력
)
{
    printf_s("*--*--*--*--*--*--*--*--*--*\n");
    printf_s("『%s의 스테이터스』\n", attname); // 플레이어, 또는 몬스터 (질문: *attname이 아닌 이유?)
    printf_s("『공격력: %d』\n", att);
    printf_s("『체력: %d』\n", hp); 
    printf_s("*--*--*--*--*--*--*--*--*--*\n");

}


int main()
{
    int playeratt = 10;//pl의 공격력(인간)
    int playerhp = 70; //pl의 체력

    int monsteratt = 15; //몬스터 공격력(너구리)
    int monsterhp = 50; //몬스터 체력


    while (true)
    {
        system("cls"); // 화면의 모든 글자 삭제 

        status_print("인간", playeratt, playerhp); // player(인간) 스탯
        status_print("너구리", monsteratt, monsterhp); // monster(너구리) 스탯 
        _getch();

        damage_print("인간", "너구리", playeratt); // 인간이 너구리를 공격 
        _getch();

        int before_monster_hp = monsterhp; // 변경되기 이전의 몬스터hp를 before_monster_hp에 저장
        monsterhp -= playeratt; // 인간 > 너구리 공격실행 후 너구리 hp 감소

        _getch();

        printf_s("너구리의 체력이 %d에서 %d로 감소합니다.", before_monster_hp, monsterhp);
        _getch();


        if (monsterhp <= 0)
        {
            printf_s("너구리는 야생으로 돌아갔습니다.\n\n인간의 승리입니다.");

            std::cout << R"( 

            
                 ----  .__o
               ----- _-\_<,
               ---  (*)/'(*)


            그 후로 인간은 오래오래 행복하게 살았습니다.. 
                         
          )" << '\n';

            _getch();
            break;
        }

        system("cls");

        status_print("인간", playeratt, playerhp); // player(인간) 체력 변화 없음
        status_print("너구리", monsteratt, monsterhp); // 변경된 monster(너구리) hp
        _getch();


        damage_print("너구리", "인간", monsteratt); // 너구리가 인간을 공격 
        _getch();

        int before_player_hp = playerhp; // 변경되기 이전의 플레이어hp를 before_player_hp에 저장
        playerhp -= monsteratt; // 너구리 > 인간 공격 후 인간 hp 감소

        _getch();

        printf_s("인간의 체력이 %d에서 %d로 감소합니다.", before_player_hp, playerhp);
        _getch();


        if (playerhp <= 0)
        {
            printf_s("인간을 내쫓는데 성공했습니다.\n\n너구리의 승리입니다.");

            std::cout << R"( 

            
                   __
                 >(' )
                   )/
                  /(
                 /  `----/
                 \  ~=- /
               ~^~^~^~^~^~^~^

            그 후로 너구리는 오래오래 행복하게 살았습니다.. 
                         
          )" << '\n';


            _getch();
            break;
        }

    }

}

