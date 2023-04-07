#pragma once
#include <assert.h> // assert(false);를 걸어둔 부분에서 터지세 함. 
#include <Windows.h> // 메세지 창을 띄워줌 


void MsgBoxAssert(const char* _Text) // Assert와 결합한 함수의 예시. 타이틀은 에러로 고정. 
{
    MessageBoxA(nullptr, _Text, "Error", MB_OK);
    assert(false);

}

// define을 활용해서 assert와 에러창을 결합 후,호출스택으로 볼 필요 없이 바로 에러가 난 곳으로 이동하게 해줌 

#define MsgBoxAssert(Text) MessageBoxA(nullptr, Text, "Error", MB_OK); assert(false); 
