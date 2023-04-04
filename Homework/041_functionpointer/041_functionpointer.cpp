// 060_FunctionPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 이 함수도 프로세스로 메모리에 올라갈것이기 때문에.
// 위치가 있을수밖에 없다.
// 이 위치는 정해져 있어요.
void PlayerAttack()
{
	printf_s("플레이어가 공격합니다.");
}

void PlayerMove()
{
	printf_s("플레이어가 이동합니다.");
}

// 문법적으로도 어려워하는 부분이고.
// 행동을 변수로 마드는 것입니다.

class PlayerMoveButton
{
public:
	// void(*Ptr)();

	void Click()
	{
		PlayerMove();
	}
};

class PlayerAttackButton
{
public:
	// void(*Ptr)();

	void Click()
	{
		PlayerAttack();
	}
};

class UIButton
{
public:
	void(*Ptr)() = nullptr;

	void Click()
	{
		if (nullptr == Ptr)
		{
			return;
		}

		Ptr();
	}
};



int main()
{
	{
		UIButton PlayerAttackButton;
		UIButton PlayerMoveButton;
		PlayerAttackButton.Ptr = PlayerAttack;
		PlayerMoveButton.Ptr = PlayerMove;
		PlayerAttackButton.Click();
		PlayerMoveButton.Click();
	}

	{
		int ArrValue[20];
		int* Ptr = ArrValue;
		*Ptr;

		// ArrValue = int[]
		// Ptr = int*
		// *Ptr = int
		// Ptr[0] = int
		// Ptr[1] = int



		int* ArrTest[20];
		int** PtrAAA = ArrTest;
		*PtrAAA;

		// ArrTest = int*[]
		// PtrAAA = int**
		// *PtrAAA = int*
		// PtrAAA[0] = int*
		// PtrAAA[1] = int*



	}

	{
		// void(*Ptr)();

		// void(*)()

		void(*ArrFunction[20])();
		ArrFunction[0] = PlayerAttack;
		void(**PtrTest)() = ArrFunction;
		PtrTest[0]();
		int Size = sizeof(PtrTest);

		// ArrTest = void(*[])()
		// PtrTest = void(**)()
		// *PtrTest = void(*)()
		// PtrTest[0] = void(*)()
		// PtrTest[1] = void(*)()

		// sizeof(PtrTest) == 8

	}

	// 리턴값 (* 함수포인터명 ) (인자) 
	//void(*Ptr)() = PlayerAttack;
	//Ptr();
	//Ptr = PlayerMove;
	//Ptr();

}
