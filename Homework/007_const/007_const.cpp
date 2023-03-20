#include <iostream>

// 함수의 스택에서의 메모리 크기는 컴파일시 
// 고정되어야 하기 때문이다.
// ex) c++의 함수의 실행흐름을 만들기 위한(스택크기)는
//     exe파일에 이미 다 정의되어 있어야 한다.
int main()
{
    "Testchar";

    int Value = 20;

    const bool cb = 20;

    const char cc = 20;

    // 한번더 보게 될것
    const int ci = 20;


    // 특정 자료형앞에 const 키워드를 붙이면
    // 그 메모리의 비트적 상수화를 시킨다.

    const int ArrSize = 30;

    // ArrSize가 상수화 (read only) 가 되었으므로, 이제 배열의 인덱스로 사용할 수 있게 됨. 
    // int Value[ArrSize] = {};

    int Value[ArrSize] = {};

    // 단, const를 사용한 변수는 재선언할 수 없다. 
    // int ArrSize = 15; <- 이렇게 해도 안 바뀜. 이미 고정된 값이기 때문. 
