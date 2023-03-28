// 030_globalvalue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 전역변수(데이터 ㅜㅜ영역에 존재)와 객체, 절차지향에 대한 상관관계. C++ 적인 코딩 스타일에 대하여 서술. 
// 클래스: 선언인 동시에, 그 객체가 어떻게 쓰일지 알려주는 설계도. 

// 클래스 static 전역변수에 대해서 익힘. 


#include <iostream>

int monster::monstercount = 0; // 6. 메모리 선언(전역스ㅌ태틱 변수이 초기화)


// static const int monstercount = 3;
// int arr[monstercount][monstercount] 는
// int arr[3][3] 과 동일.
// 그러나

// static const int monstercount;
// int arr[monstercount][monstercount] 는
// 컴파일러가 mostercount를 알수없는 수로 인식함 (초기화가 안 되엇기 때문. 변하지 않는 수는 맞지만) 


class player {

public:
    void damage()
    {
        // int value = 10; 4. 플레이어도 밸류를쓸 수 있고 
    }
private:

};

//6. 새로운 전역함수 선언함. 근데 이것을 몬스터 클래스만 사용할 수 있게 하고 싶음. 
int monster1122()
{
}

// 4. int value; >> 자 이게 전역변수임 

// 2. 새로운 문법. 
class monster {

public:
    static int monstercount // 자 아래에서 올라와서 일단 선언한다 

        // int value = 20; 
        // 4. 몬스터도 쓸 수 있게되어버리게됨. 
            // ㄴ 근데 내가 원하는건 몬스터만 사용할 수 잇는 변수를 원함. 
            // 그때 사용하는게 static 멤버 변수 인거임. (ex. 몬스터 클래스만 얘를 참고해서 쓸 수 잇도록) 


        int hp1; // 객체 하나 넣어주고 

    void print(); // 2. 선언만 하되, 구현이 안 되어있는 코드. 


private:
    // 현재까지 만들어진 모든 몬스터의 수 (세고 싶어서 만듬) 
    // 즉, 객체가 몇개냐는 의미. 
    // 
    // 
    // int monstercount; 
    // static 멤버변수. (메모리 - 데이터 영역에 위치) 
    // static int monstercount; <<- 이렇게 써야 잘 들어감. (퍼블릭에 선언하겠음)  
    static int monstercount; // 몬스터 클래스만 사용가능한 전역변수 선언 
    // 이게 몬스터를 세기 위한 코드 
public:
    monster()
    {
        ++monstercount;
    }

};

int test = 10;
// 1. 
// 이건 전역변수(=객체에서 벗어난 존재), 얘에 의지해서 코딩하는건 객체지향이 아님! 
// 절차지향이란? : 전역에 하나 두고, 그걸 계속 돌려쓰는 방식. 
// ㄴ 이게 있는건.. c 스타일 코딩도 C++은 지원하기 때문임. 그게 다임. 
// 
// 객체지향이란? : 오직 클래스와 객체로만 코딩하는 것. 그 이외는 인정하지 않음. (c++) 
// ㄴ 모든 것이 객체 내부(클래스)에 존재해야 한다는 의미. 

int main()
{


    // 총 4마리가 있는 상황 
    // monster nmonster0;
    // monster nmonster1;
    // monster nmonster2;
    // monster nmonster3;

    int count


        // 5. 그래서 몬스터 카운트를 몬스터만 쓸 수 있게함. 이때 이건 "정의" 임. 메모리까지 배정 된 상태. 
        // monster::monstercount = 300; // 단, static 전역변수의 초기하는 전역에서만 가능함. 지역에서는 선언만. 



         // 3. print 를 불러봅시다. 
         // 이거 왜 오류뜨는지 코드 확인. 
         // >> 오류가 뜸" 확인할 수 없는 외부기호" = 이것은 내가 설계도만 쓰고, 구현을 하지 않았다는 의미임. 


};

