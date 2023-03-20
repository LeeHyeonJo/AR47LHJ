// 011_복합할당연산자.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int Left = 0b00000000000000000000000000000010;
	int Right = 0b00000000000000000000000000000001;
	int Result = 0b00000000000000000000000000000000;

	// 비트단위 연산자.
	// 0b00000000000000000000000000000000
	// Not
	Result = ~0;


	// Left 0b00000000000000000000000000000010
	// Right 0b00000000000000000000000000000001
	// Result 0b00000000000000000000000000000000

	// and(&) = 두 개의 비트 패턴에서 모든 대응하는 비트가 1인 경우에만 1을 반환.
	Result = Left & Right; // 이건 결과: all 0이 되고 결국 result도 0이 된다. 

	// or(|) = 두 개의 비트 패턴 중 하나라도 대응하는 비트가 1인 경우에 1을 반환.
	Result = Left | Right; // 결과:0b0011 -> 3이 됨 

	// xor(^) // 두 개의 비트 중 "하나만 1인 경우" 결과 비트가 1이 됨. 
	Result = Left ^ Right;// 결과: 0b0011 -> 3

	// NOT(~) // 비트를 반전. 0은 1로 1은 0으로 바뀐다. 





	// 복합할당 연산자.
		// 특정 메모리영역의 값을 기반으로 하는 이항 연산자 
		// 특정 메모리를 수정하며 변형함. 

		//덧셈 대입	a += b	예	예	T & T::operator+=(const T & b);	T& operator+=(T & a, const T & b);
		//뺄셈 대입	a -= b	예	예	T & T::operator-=(const T & b);	T& operator-=(T & a, const T & b);
		//곱셈 대입	a *= b	예	예	T & T::operator*=(const T & b);	T& operator*=(T & a, const T & b);
		//나눗셈 대입	a /= b	예	예	T & T::operator/=(const T & b);	T& operator/=(T & a, const T & b); <- 여기까지 사용해봄. 
		//모듈러 대입	a %= b	예	예	T & T::operator%=(const T & b);	T& operator%=(T & a, const T & b);
		//비트 AND 대입	a &= b	예	예	T & T::operator&=(const T & b);	T& operator&=(T & a, const T & b);
		//비트 OR 대입	a |= b	예	예	T & T::operator|=(const T & b);	T& operator|=(T & a, const T & b);
		//비트 XOR 대입	a ^= b	예	예	T & T::operator^=(const T & b);	T& operator^=(T & a, const T & b);
		//비트 왼쪽 시프트 대입	a <<= b	예	예	T & T::operator<<=(const T & b);	T& operator<<=(T & a, const T & b);
		//비트 오른쪽 시프트 대입	a >>= b	예	예	T & T::operator>>=(const T & b);	T& operator>>=(T & a, const T & b);

	int Value = 20;

	Value = Value + 10; // v= 30

	// 복합
	Value += Value; // v(30)에 v(30), 자기자신을 더하고 다시 v에 넣어준다. -> 60
	Value = 1; // 재선언 -> v는 60에서 1로 바뀜 

	//비트 시프트 연산자 << & >> 
	// 변수의 값을 이진수로 나타내고, 왼쪽&오른쪽으로 우항(3) 비트만큼 시프트한다. 
	// V에 1(0001-이진수)이 들어있으므로, 3비트만큼 왼쪽으로 시프트하면 
	// 1000이된다. 이는 8이므로 최종적으로 v에 8이 들어가게 된다. 
	Value = Value << 3;

	// heal
	Value = Value + 30;
	Value += 30;




	{

		//복합할당 연산자 예시 연습 

		// 1. 덧셈대입
		int x = 10;
		x += 5; // 15

		// 2. 뺄셈대입
		int z = 10;
		z -= 1; //9

		// 3. 곱셈대입
		int a = 4;
		a *= 2; //  8

		// 4. 나눗셈 대입
		int w = 6;
		w /= 2; // 3

		int k = 0;

	}
}

