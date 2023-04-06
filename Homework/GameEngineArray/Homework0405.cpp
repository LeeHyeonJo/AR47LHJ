#include <iostream>
#include "GameEngineArray.h"

// 숙제 1 해결. Arr0[10] -> ReSize(5)시 기존 배열의 값(0~9) 에서 (0~4)만 출력되도록 변경. 
// 숙제 2,3,4 미해결. 

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
        // 컴파일러에서 지원하는 Arr형에는 operator = 함수를 구현하지 않았다.
        int Arr0[10] = { 0, 1, 2, 3 ,4, 5,6 };
        //int Arr1[3];
    }

    {
        //               600번지
        // int* ArrPtr = new int[20]
        GameEngineArray Array0(10);


        for (size_t i = 0; i < Array0.Count(); i++)
        {
            Array0[i] = i;
        } 

        printf("재할당 전 크기 : %d \n", Array0.Count());

        Array0.ReSize(5); // 숙제1. 기존의 데이터를 보존하며 Resize가 작동하도록 수정할것. (0~4까지 출력되어야 함) 

        for (size_t i = 0; i < Array0.Count(); i++)
        {
            printf_s("%d\n", Array0[i]);
        }

        printf("재할당 후 크기 : %d \n", Array0.Count());

        // GameEngineArray Array1;
        // Array0 = Array1;
    }

   /* {
        GameEngineArray Array0(20);
        GameEngineArray Array1(10);

         숙제3: Array1 = Array0;이 왜 터지는지 이해하고 고쳐라.
         Array1 = Array0;
         중간 값을 잘라먹을 수 있게 구현하라는 의미
         ㄴ 배열의 크기가 더 작은 쪽에 큰 쪽을 넣도록 하고 있다. 
         하지만 이 경우 범위를 넘어선 메모리에 접근하여 쓰기를 시도하기 때문에 문제가 발생한다. . 
    }

    {
        GameEngineArray Array0(10);
        GameEngineArray Array1(5);

        for (size_t i = 0; i < Array0.Count(); i++)
        {
            Array0[i] = i;
        }

         숙제4 완전히 동일한 배열이 되게 만들어주세요.
         Array1 10개 짜리 배열이 되고 0 1 2 3 4 5 6 7 8 9
        Array1 = Array0;

        for (size_t i = 0; i < Array1.Count(); i++)
        {
            printf_s("%d\n", Array1[i]);
        }

    }*/

}
