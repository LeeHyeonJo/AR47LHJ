#pragma once
#include <assert.h> // assert(false);�� �ɾ�� �κп��� ������ ��. 
#include <Windows.h> // �޼��� â�� ����� 


void MsgBoxAssert(const char* _Text) // Assert�� ������ �Լ��� ����. Ÿ��Ʋ�� ������ ����. 
{
    MessageBoxA(nullptr, _Text, "Error", MB_OK);
    assert(false);

}

// define�� Ȱ���ؼ� assert�� ����â�� ���� ��,ȣ�⽺������ �� �ʿ� ���� �ٷ� ������ �� ������ �̵��ϰ� ���� 

#define MsgBoxAssert(Text) MessageBoxA(nullptr, Text, "Error", MB_OK); assert(false); 
