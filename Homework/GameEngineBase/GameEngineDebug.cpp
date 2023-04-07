#include "GameEngineDebug.h"
#include //crtdbg쓸수있게 헤더 인클루드 

GameEngineDebug::GameEngineDebug() 
{
}

GameEngineDebug::~GameEngineDebug() 
{
}

GameEngineDebug::LeakCheck() // 5. leak 체크 -> 그 다음은 0407숙제 폴더에서 멀하고있는거임?? 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); 

}

