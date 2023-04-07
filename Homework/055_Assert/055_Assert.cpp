// 055_Assert.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 이 필기는 아래에서부터 보셈. 

#include <iostream>
#include "Player.h" 
//#include <assert.h> // assert(false);를 걸어둔 부분에서 터지세 함. 
//#include <Windows.h> // 메세지 창을 띄워줌 


//void MsgBoxAssert(const char* _Text) // Assert와 결합한 함수의 예시. 타이틀은 에러로 고정. 이 함수를 메인에서 쓸거임. 다시 메인으로. 
//{
//    MessageBoxA(nullptr, _Text, "Error", MB_OK); 
//    assert(false);
//
//}


//void MsgBox(const char* _Text, const char* _Title) // 이렇게가 기본 형태. 그런데 우린 에러메세지를 띄울거라서 타이틀 이름을 에러라고 고정할거임. 다시 위로. 
//{
//    MessageBoxA(nullptr, _Text, _Title, MB_OK); 
//    assert(false);
//
//}

int main()
{
    //MessageBoxA(nullptr, "(내용)aaa", "(제목)오류입니다", MB_OK); // 메세지 박스를 띄워줌. MB_OK = 확인 버튼 1개 띄워줌. 
    //assert(false); 
    // 이렇게 2개를 다 쓰기 귀찮으니까, 함수로 엮어서 사용하게 됨. 상단으로. 
    //MsgBoxAssert("너굴너굴"); // 그 런 데!! 이렇게 함수로 쓸 때 문제점이 있음. class를 예시로 설명. 
    //std::cout << "Hello World!\n";

    Player NewPlayer{}; 

    NewPlayer.Damage(0);

}

// 추가 > 헤더 > 베이스 헤더 생성 후, 그 안에 assert와  windows 헤더 2개&메세지박스 에러 함수(9~14열)을 넣어줌. 

