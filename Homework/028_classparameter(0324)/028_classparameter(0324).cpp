// 028_classparameter.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 1. 함수의 인자에 레퍼/포인터 쓰는 경우 
// 2. 최적화(함수 인자를 포인터,레퍼,그냥 받을지로 고민해야하는 이유) = 메모리를 적게 쓰는게 좋다. 


#include <iostream>

player() //32바이트인 이유..int값 8개 들어가서 
{
    int value1;
    int value2;
    int value3;
    int value4;
    int value5;
    int value6;
    int value7;
    int value8;
};

// 렙업시 스텟창 띄워주는거 
// << 함수의 인자에서 *,&쓸때..>>

//레퍼를 쓰는 경우 
void statusrender(const player& status1) // 1. player에 const 붙인 이유 = 변하면 안되는 인자라서 
{
    //  2. 레퍼런스 쓰는 이유: 8바이트라서 (이거 설명 다시 듣기) 
     // -> 레퍼 안써도 되긴 함. 근데 player 쌩 선언해서 32바이트 쓰기보다
   // 레퍼로 지정하면 8바이트만 쓰면 더효율적이므로 대체로 const &를 씀. 
        // 이게 최적화 



}

// 전역에 있을 경우
// 데이터 영역에존재하므로, 프로그램이 종료되어야 사라짐. 

int value;

// 질문1: 보이지 않는 메모리값이 왜 존재하는가?? (곡 확인하기) 
int aaa()
{
    int value = 20;
    return value;
}

int main2(aaa()) // <- aaa() 가  20,value int인 그것(4바이트)를 받음.
// 정확히는 코드 영역에 잇는 20을 복사한 int value (이게 바로 보이지 않는 메모리) 값을 가져온거임. 
// 이거에 

{
    // ****안되는 코드 (영상 보고 따라쳐보기)****
    // 아마 내 기억으론 value 그냥 불러서 썼던것 같음. (왜냐면 value는 함수가 끝나면 사라지니까) 


    if (aaa()) // 이게 되는 이유 
        // aaa() 가 보이지 않는 메모리(int value,20)이 들어감 
         // 즉, 존재하는 메모리값을 참조하기 때문. 
    {

    }

};

// 질문2: ***함수의 메모리 그리는 과정 꼭 보고 따라 그려보기.**** 
// >> class player를 왜 참조하지 않았고, 리턴하지 않은 이유를 생각하기
// >> 지역변수에 레퍼를 걸어버리면, 이건 타 함수에서 참고할 수 없다(정도로 이해함)


// 포인터를 쓰는 경우 
void statusrender(const player* status) // player에 포인터를 쓰는 경우 (레퍼와 달리) 
// 1. 예시로는 플레이어가 1마리도 없는(null값)인 가능성이 있을 때. 
{
    // 방어코드라고 함. <- 이건 nullㅣ값이 들어올 수 있으니, 그 경우 이렇게 리턴하라고 처리해둔 것 
    if (nullptr == player)
    {
        return;
    }

    // player->value0 = 20; <<- 무조건 터짐(null) 

}


int main()
{
    int value = sizeof(player);


}


