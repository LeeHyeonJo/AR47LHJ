#pragma once
#include "ConsoleGameMath.h"
#include "GameEngineArray.h"

// �̰� 1�ܰ�
// �ٺ����� �ٺ� ���� ���� 
class ConsoleGameScreen
{
public:
	// Ŭ���� ���ο� ���������� �����Ҽ��� �ֽ��ϴ�.
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	static int2 GetScreenSize(); // static ����  
	//{
		//return MainScreen.GetScreenSize(); //�ѹ� �� �������ִ°ǵ� ���� ��Ȳ�� �ƴѤ� 
	//}

	void ScreenClear();

	void ScreenPrint() const;

	bool IsScreenOver(const int2& _Pos) const;

	void SetScreenCharacter(const int2& _Pos, char _Ch);

protected:

private:
	// char Arr[ScreenYSize][ScreenXSize] = { 0, };

	// 8. �̰��� �������� ������ ������ �ڵ� ����
	// ��ǳ ������ �����Ͷ�� �� ������. 

	// ���� �߿���!!!!!!!!!!! class GameEngineArray ���ο� �մ� ����� �����ϱ�. 
	// 
	// char** ArrScreen = nullptr; // �̰Ͱ� �Ʒ��� ���� �ڵ��� �� ������ ��. �׷��� ���̰� ����. ��� ��� ���(ex. delete)�� �� ���־� ��. 

	GameEngineArray<GameEngineArray<char>> ArrScreen; // 6. �̰� ����ϸ� delete�� ������� �ʾƵ� �ǰ� ��. �̹� �Ҹ��ڿ��� �����صξ��� ����. cpp�� �̵�. 

	// �� �ڵ�� clas GameEngineArray�� �����Ѱ��̰�, ��� ����� �׾ȿ� ��������Ƿ� �� �ڵ庸�� �ξ� ���� ����. 


	ConsoleGameScreen();

	// �̱��� �����̶�� �մϴ�.

	static ConsoleGameScreen MainScreen;
};