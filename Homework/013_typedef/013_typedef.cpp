// 013_typedef.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 근데 써봤자 컴파일러가 빨라지거나 그러진 않음~!! 

// 자료형 size+t: 언사인드 _int64를 size_t라고 부르겠다
// typedef       언사인드 _int64 size_t;
// 언사인드 _int64 == size_t;   이라는 의미임. 

// 사용자 정의 자료형의 일종. : 언사인드 __int64가 너무 기니까 size_t가 됨. 
// 사람 편하라고 줄인거임. 모든 문법은 사람 편하라고 만들었다는 것 잊지 말것. 

#include <iostream>


// typedef __time64_t time_t; //타임 T에도 타임 T를 취할 수 있음. >> 이거 물어보기. 
// typedef __int64 // 존나 긴 자료형을 별명붙여서 줄이기 위함. 

// 15번째 라인 설명:
// typedef int myint // int 가 마음에 들지 않아서 마이 인트로 바꿈 (자료형의 이름에 별명을 붙여서 쓸 수 있다는 뜻) 
// typedef myint mmint // myint 가 마음에 들지 않아서 mmint로 바꿈 <- typedef를 또 쓸 수 있다는게 이런 뜻임. 

// 변수나 자료형 위에서 f12 - 그 선언으로 이동(변수가 최초로 만들어진 시점) 
// ctrl shift g : 샵 인클루드<파일명>의 내용으로 이동. 


int main()
{
    time_t DTime = time(0);
}

