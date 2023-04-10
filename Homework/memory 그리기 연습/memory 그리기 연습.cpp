// memory 그리기 연습.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
// 매일매일 간단한 함수 구현 1개 & 메모리 작동방식 직접 그려보기. 

// 연습문제 1. 
//1.함수 이름은 max로 하고, 매개변수는 int형으로 선언합니다. 
//2, 함수의 반환형은 int형으로 합니다.
//3, 함수를 호출하여 반환된 결과를 출력하는 main 함수도 함께 작성하세요.
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int x, y;
    printf_s("두 개의 정수를 입력하세요: ");
    scanf_s("%d %d", &x, &y);
    printf_s("입력한 두 수 중 큰 수는 %d입니다.\n", max(x, y));
    return 0;
}

// 메모리 그려보기 // 


