// GameEngineArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "GameEngineArray.h"

int main()
{
    // 외우셔야 합니다.
// 윈도우 전용 삭제하지 않은 힙 메모리 출력에 표시. 
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); 

    GameEngineArray NewArr(0); 


    // int* Arr = new int[0];




    //{
    //    // 컴파일러에서 지원하는 Arr형에는
    //    // operator = 함수를 구현하지 않았다.
    //    int Arr0[10] = { 0, 1, 2, 3 ,4, 5,6 };
    //    int Arr1[10];
    //    // Arr1 = Arr0;
    //}

    //{
    //    //               600번지
    //    // int* ArrPtr = new int[20]
    //    GameEngineArray Array0(10);


    //    for (size_t i = 0; i < Array0.Count(); i++)
    //    {
    //        Array0[i] = i;
    //    }

    //    //          700번지
    //    // ArrPtr = new int[10]
    //    // 숙제 1 기존의 데이터를 보존하는것을 말하는것이고
    //    // 숙제 2 줄어들든 커지든 데이터는 보존되어야 한다.
    //    // Array0.ReSize(5);
    //    Array0.ReSize(15);

    //    // Array0.ReSize(15);

    //    for (size_t i = 0; i < Array0.Count(); i++)
    //    {
    //        printf_s("%d\n", Array0[i]);
    //    }

    //}

    //{
    //    GameEngineArray Array0(10);
    //    GameEngineArray Array1(5);

    //    // 숙제3 왜 터지는지 이해하고 고쳐라.
    //    Array1 = Array0;
    //}

    //{
    //    GameEngineArray Array0(10);
    //    GameEngineArray Array1(5);

    //    for (size_t i = 0; i < Array0.Count(); i++)
    //    {
    //        Array0[i] = i;
    //    }

    //    // 숙제4 완전히 동일한 배열이 되게 만들어주세요.
    //    // Array1 10개 짜리 배열이 되고 0 1 2 3 4 5 6 7 8 9
    //    Array1 = Array0;

    //    for (size_t i = 0; i < Array1.Count(); i++)
    //    {
    //        printf_s("%d\n", Array1[i]);
    //    }

    //}


    // std::cout << "Hello World!\n";
}






//#include <iostream>
//#include "GameEngineArray.h"
//
//// 숙제 1,2 해결함. (resize 해결) 
//// 숙제 3,4 미해결. 
//
//int main()
//{
//    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//    {
//        // 컴파일러에서 지원하는 Arr형에는 operator = 함수를 구현하지 않았다.
//        int Arr0[10] = { 0, 1, 2, 3 ,4, 5,6 };
//        //int Arr1[3];
//    }
//
//    {
//        //               600번지
//        // int* ArrPtr = new int[20]
//        GameEngineArray Array0(10);
//
//
//        for (size_t i = 0; i < Array0.Count(); i++)
//        {
//            Array0[i] = i;
//        } // 배열 내부 값 채워주는 중. 
//
//        printf("재할당 전 크기 : %d \n", Array0.Count());
//
//        Array0.ReSize(5); // 숙제1. 기존의 데이터를 보존하며 Resize가 작동하도록 수정할것. (0~4까지 출력되어야 함) 
//
//        for (size_t i = 0; i < Array0.Count(); i++)
//        {
//            printf_s("%d\n", Array0[i]);
//        }
//
//        printf("재할당 후 크기 : %d \n", Array0.Count());
//
//        // GameEngineArray Array1;
//        // Array0 = Array1;
//    }
//
//
///////////// 여기까지 숙제 1,2. 하단이 숙제 3,4 ////////////////////// 
//
//
//    {   //숙제3: Array1 = Array0;이 왜 터지는지 이해하고 고쳐라.
//        // 얕은 복사를 깊은 복사가 되도록 참조하는 메모리까지 복사하게 코드를 수정해주면 끝. 
//        GameEngineArray Array0(20);
//        GameEngineArray Array1(10);
//
//      
//         Array1 = Array0; 
//
//    }
//
//
//    //숙제4 완전히 동일한 배열이 되게 만들기. 
//    //Array1(5)가 arr0처럼 10개짜리 배열이 되고, 그 안에 arr0(10)과 동일한 값이 들어가야 한다. 
//    {
//        GameEngineArray Array0(10);
//        GameEngineArray Array1(5);
//
//        for (size_t i = 0; i < Array0.Count(); i++)
//        {
//            Array0[i] = i;
//        }
//
//        // 여기에서 복사 잘 되는지 확인 -> 아까 한 얕복을 깊복으로 바꿔주는 과정에서 얘도 문제없이 돌아감. 
//        Array1 = Array0; 
//
//        for (size_t i = 0; i < Array1.Count(); i++)
//        {
//            printf_s("%d\n", Array1[i]);
//        }
//
//    }
//
//}
