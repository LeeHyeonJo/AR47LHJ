// Homework0324.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 연산자 오버로드 연습(미완) - 0323 두번째 영상, 0324영상에 해설 있음(나중에 해보기) 
// unnamed value에 대한 개념 재학습 

// int
int Realnumber = 10;
(Realnumber + 10);
(Realnumber += 10) = 10; // int라면 가능한 연산자 (다 구현되어 있으므로) 

// number class에서 구현한 연산자(operator)
Number newnumber = 10;
(newnumber += 10) = 10;

	// unnamed value > 좌항을 계산하며 보이지 않는 4바이트 메모리 생성. 그 메모리에 10 대입하는 건 불가능. 
	// const int operator+(const int& _a)	
	// {"덧셈연산자 정의"} >> 12항같은건 불가능 
	// 
	// ---------되게 바꿔봅시다-------- (10을 대입하는게 아니라 좌항의 연산이 끝난 나 자신을 다시 리턴하면 됨) 
	// 
	// Number& operator+=(const int& _a) // 클래스 이름 
	// {Value += _a; // 대입연산자를 여기에 구현해두고 
	// return *this} // 대입연산자의 계산이 끝난 좌항을 참조로 받은 클래스 & this로 리턴한다 
			//  ㄴ this의 의미: Number(class이름)* const this(Ptr); // 0324 중간즈음 


#include <iostream>

class Number
{

private:
	int Value; // 디폴트 생성자를 정의하기 전에 꼭 이렇게 해줘야하나보다.  넘버 클래스는 int형 value를 하나 갖고 있겠다는 뜻. 


public:
	Number(int _Value) // 멤버이니셜라이저를 해줄거임. 객체가 생성될떄 걔넨 어떤 양식일지를 말하는 거로 이해했음. 
		: Value(_Value)
	{

	}


};

int main()
{
	{
		int Value = 10;
		Value + 10;
	}


	{
		Number Value = 10; // 못받은 이유. 생성자가 없어서. 
		Value + 10; // 더하기가 안되는 이유. 연산자 안만들어서. (오퍼레이터가 연산자라는걸 이제 알았음..) 

		// 연산자 오버로딩 하는듯. 간단히 말하면 "사용자 정의 연산자". 이걸 이용해서 내가 정의한 클래스에 대해 연산자를 오버로딩할 수 있음. 
		// 해당 클래스 객체에 대한 특정 연산을 수행가능할 수 있게 함.이것으로 클래스 객체 간 연산을 더 직관적으로 편리하게 수행 가능. 

	}
}


