#include "GameEngineDebug.h"
#include //crtdbg�����ְ� ��� ��Ŭ��� 

GameEngineDebug::GameEngineDebug() 
{
}

GameEngineDebug::~GameEngineDebug() 
{
}

GameEngineDebug::LeakCheck() // 5. leak üũ -> �� ������ 0407���� �������� ���ϰ��ִ°���?? 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); 

}

