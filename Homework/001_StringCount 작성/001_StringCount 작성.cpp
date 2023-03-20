// 001_StringCount 작성.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 0을 포함할지 아닐지는 직접 정하기. 
// <부족한 점> 
// const, 포인터 변수의 사용 이유, 복합할당 연산자, 다음 문자로 이동(함수의 원리) 다시 익히기 
// char* String, *p++ = *String;,  String++; <- 이해했는데, 함수의 작동 원리를 아직 덜 이해함. 
#include <iostream>

int StringCount(const char* String) // 문자열의 문자 갯수를 세어주는 함수. 문자열의 길이를 파악하기 위해 포인터를 사용.(기억하기) 
                                    // 문자열의 첫 번째 글자의 메모리 주소를 포인터를 알아내면, 각 문자에 반복적으로 접근 가능하기 때문!
{                                   // 각 함수의 작동 원리 다시 익히기. 
    int count = 0;
    while (*String != '\0') // 포인트 변수 사용, 0이 나올때까지 반복한다는 의미. 문자열의 끝까지 반복
    {
        count++; // 문자열 길이를 1씩 증가 
        String++; // 다음 문자로 이동 ▶ 다음 문자도 반복해서 훑어야하니까..?
    }
    return count;
}


int TrimDelete(char* String) // 공백을 전부 삭제. 입력한 문자열(String)의 포인터를 받고, 해당 문자열의 공백을 모두 삭제 후 반환 
{
    char* p = String;
    while (*String != '\0') // 포인트 변수 사용, 0이 나올때까지 반복한다는 의미. 문자열의 끝까지 반복
    {
        if (*String != ' ') // If문 사용. 공백이 아닌 문자는 그대로 유지
        {
            *p++ = *String; // ▶ p가 가리키는 위치에 String이 가리키는 값을 저장. p를 다음 위치로 이동시키는 것을 반복하면서 문자열을 복사하는 역할
                            // 문자열을 한 글자씩 복사하면서 p가 다음 메모리 위치를 가리키도록 해서 문자열을 복사할 수 있음. 
        }
        String++; // 다음 문자로 이동
    }
    *p = '\0'; // 문자열의 끝을 나타내는 null 문자 추가
    return 0;
}



int StringToInt(const char* String) // 문자열->정수로 변환. 입력한 문자열의 포인터를 받고, 해당 문자열을 정수로 변환 후 반환
{
    int result = 0;
    while (*String != '\0') // 문자열의 끝까지 반
    {
        result = result * 10 + (*String - '0'); // 문자를 정수로 변환하여 더하기

        String++; // 다음 문자로 이동
    }
    return result;
}



int main() // 항상 main 부터 실행 
{
    int Return0 = StringCount("aaaa");
    int Return1 = StringCount("aaaa ggg sss");

    char Arr0[30] = "a b c d e";
    char Arr1[30] = "a    b c    d    e";
    char Arr2[30] = "ab    cde    ";

    TrimDelete(Arr0);
    printf_s(Arr0);

    TrimDelete(Arr1);
    printf_s(Arr1);

    TrimDelete(Arr2);
    printf_s(Arr2);

    // 영어나 다른글자가 섞여 들어가있는것을 가정하지 않는다.
    int RValue0 = StringToInt("1111");
    int RValue1 = StringToInt("432");
    int RValue2 = StringToInt("4523312");
    int RValue3 = StringToInt("432231");
}

