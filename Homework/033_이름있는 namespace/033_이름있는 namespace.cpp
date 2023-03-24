// 033_이름있는 namespace.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//std에 대하여 설명 

//2. 클래스 플레이어의 의미 : 플레잉가 만들어지면, 내부에 int att가 ㅁ하ㅏ나 있어야 해 
//      // ㄴ 다시말해 플레이어의 스펙, 만들엊어 질때의 내용들은 "코드" 영역에 들어가있음 
//      // 실제로 실행되는건 프로그램이 실행될때 그 당시니까 
//      // 즉, 클래스는 설계도라고 이해하면 됨. (진짜 실행된 것이 아니라는 것을 이해해야 함) 
//메인에서 클래스 쓴거라 만든거임 


class player // 코드 영역의 300번지에 존재하는 player를 쓰겠다는 것. 
{
    int att; 
};


class player // 코드 영역의 300번지에 존재하는 player를 쓰겠다는 것. (이건 일부러 바꿔준거임) 
            // 따라서 같은 클래스 이름을 선언하면 컴파일러 에러! 
            // 이미 그 클래스 이름에 해당하는 메모리에 내용이 들어차 있기 때문. 안됨! 
{
    int att;
};

// 주의할 점. 같은 영역에 같은 이름의 클래스가 존재하면 안됨 // 
// >> 이를 보안하기 위해 만들어진 것이 namespace
// 근데 애초에 클래스를 안 겹치게 이름을 짬. 


//namespace: 요약 - 같은 이름의 클래스를, 각 프로그래머 별로 사용할 수 있게 대분류해주는 것 

namespace aprogrammer
{
    class item 
    {
        int item;
    }
};

namespace bprogrammer
{
    class item  
    {
        int item;
    }
};


// 네임스페이스는 중펍할 수 있따. 
namespace cprogrammer
{
    namespace bprogrammer
    {
        class item
        {
            int item;
        }
    }
};

// :: 에 대한 추가설명 
class monster
{
public:
    int att;
};

class raccoon
{
public:
    int att;
};

// 같은 att 라는 변수 이름이어도 오류 안나는 이유
// 컴파일러는 보든 변수를 monster::att (몬스터 안에 있는 att), raccoon:att(라군 안에 있는 att) 로 해석하기 때문에
// 헷갈릴 일이 없음. 

// 플레이어 클래스 내부의 damage와 void damage 는 다르다는 것ㄱ을 기억하기.


int main()
{

    aprogrammer::item newitema; // item에 네임스페이스라는 꼬리표를 더 붙여준거임. 둘이 다른 itemㅇ 이런게 아님 
    bprogrammer::item newitema; // 이걸 쓰는 회사가있고 아닌 회사가 있음. 회사 스타일. 
    cprogrammer ::bprogrammer :: item newiteamc // 이렇게 중첩 가능 
        // ::  비교연산자였나? 디ㅏ시 확인해보기.

    // 1. 아래의 이걸 배울거임 드디어!
    std::cout << "Hello World!\n";

    // >> 따라서 위의 설명을 토대로 std는 cout 의 namespace임을 알 수 있음. 
    // std c++는 스탠다드의 줄인말,c++의 공인임(퀄리티가 보증되었다는 뜻) 


}


// **절대 안쓰는 것: using namespace aprogrammer**
// **기본적으로 namespace를 사용하지 않겠다. 쓴다고 하더라도 using 은 사용하지 않겠다**
            // 이런걸 "코딩 스탠다드" 라고 함. 지켜야 하는 코딩 규칙. (구글 코딩 스탠다드 검색하보면 재밋어요) 
            // TD.. 테크니컬 디렉터가 되면 이런규칙 다 정할 수 있음.헉, 되고싶다. 
// **코드 한줄로 치기 절대 금지** 
// using 을 쓰지 마세용. 
// 말 뜻: aprogrammer item newitem ->  item newitem 이렇게 생략할 수 있다면 생략해라. 
// 쓰면 안되는 이유: aprogrammer,bprogrammer 둘 다 생략하게 되는 상황에서 같은 이름의 변수를 사용하면
// 컴파일러가 모호하다고 말해줌. 안됨. 

// namespace: 이름 붙여서 구분 잘 하나자는 의미인데,usig namespace를 사용하면 이름표를 때겠다는 의미가 됨. 