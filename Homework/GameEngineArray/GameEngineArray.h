#include <iostream>

typedef int DataType;

// 설명 :
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;


	// constrcuter destructer
	GameEngineArray(size_t _Value)
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{
		// ArrPtr = new int[100];
	}

	~GameEngineArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{ // 숙제 3. 의 원인(하단 2줄) // = 디폴트 복사 생성자로 인해 얕은 복사가 되었기 때문. 
		//ArrCount = _Other.ArrCount;
		//ArrPtr = _Other.ArrPtr;

		// 해결방법: 깊은 복사가 이루어지도록 복사생성자를 새롭게 정의해준다.(참조하는 메모리도 복사해야함) 
		// 3. ReSize 함수의 작용: 참조할 메모리를 새롭게 복사. 

		ReSize(_Other.ArrCount); // 1. 상대의 크기로 리사이즈 한다. 

		for (size_t i = 0; i < _Other.ArrCount; i++) // 2.배열 채우는 중, 그런데 클래스 GameEngineArray& operator=(const GameEngineArray& _Other) 
													//가 const이므로 호출가능한 멤버함수도 const 뿐. 따라서 아래 operator도 const를 붙여줌. 
		{

			ArrPtr[i] = _Other[i]; 
		}


		return *this;
	}
	// 얕은 복사를 깊은 복사가 되도록 바꿔주는 예제였음. 숙제 3 해결 -> 그런데 메모리 누수가 발생. (선생님 1,2풀이의 연속)_ 

	size_t Count() 
	{
		return ArrCount; // 이게배열의 크기 
	}

	DataType& operator[](size_t _Index) const 
	{
		return ArrPtr[_Index];
	}

	//숙제1: resize() 작동 시, 쓰레기값 대신 기존 배열의 메모리가 대입되도록 해결. 
	//힌트: 삼항연산자 사용, 기존의 있던 값에서 현재의 배열이 복사한다음 삭제해야 한다.
	void ReSize(int _Value) // 리사이즈된 배열의 크기가 인수임. _Value
	{
		//a. 기존 배열을 할당받을 빈 배열 선언. 
		int* newArrPtr = nullptr;

		//b. 배열 newArrPtr의 크기로 사용할 변수 선언. 
		int newResizeCount = 0; // 

		//c. 배열 newArrPtr의 크기(newResizeCount)와 현재 배열의 크기(ArrCount)를 비교.
		// newResizeCount>ArrCount 라면 _Value(=Resize 된 배열의 크기)를 사용. newResizeCount<ArrCount 라면 ArrCount를 사용. 

		if (_Value > ArrCount)// 5 > 10
		{
			newResizeCount = _Value; 
		}
		else
		{
			newResizeCount = ArrCount; // Arrcount를 그냥 쓴다는 뜻. ArrCo
		}

		// 삼항연산자로 선언시: 
		// _Value > ArrCount ? newResizeCount = _Value : newResizeCount = ArrCount; 이게 아니라 
		// newResizeCount = _Value > ArrCount ? _Value : ArrCount;  이렇게 받으면 됨 
		// newResizeCount = (_Value > ArrCount ? _Value : ArrCount);  이렇게 괄호 넣어서 int라고 생각하면 됨. 리턴값이 int니까. 
		// 뜻:  _Value > ArrCount가 true일시, 뒤의 _Value를 newResizeCount에 리턴. false일시 ArrCount를 리턴한다는 뜻. 

		/// a~c는 빈 배열을 선언하고 빈 배열의 크기를 결정할 변수를 정하는 과정. 

		//d. a에서 선언한 새로운 배열 newArrPtr을 힙에 동적할당. 
		newArrPtr = new int[newResizeCount];  // 힙에 [n] 크기의 배열을 선언 후 그 이름을 newArrPtr로 붙여줌. 

		//e. 기존의 할당된 배열을(ex.Array0) 새로운 배열 newArrPtr에 복사 & 값을 보존. 
		for (int i = 0; i < newResizeCount; i++) 
		{
			newArrPtr[i] = ArrPtr[i];  
		}


		//f. newAttPtr에 기존의 Array0의 복사를 확인. 이제 ArrPtr이 가르키던 arr0와 연결을 delete한다. 
		// **기존의 할당된 배열을 알고 있는것은 섣불리 지우면 안된다.** 

		// --- 선생님 풀이 1,2번 문제는 여기서 시작함 --- // 

		if (nullptr != ArrPtr)  
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		//g. 포인터 ArrPtr가 새로운 배열 newArrPtr을 가리킴. 
		ArrPtr = newArrPtr;  // 선생님 풀이 릭 발생 사유. 새로운 배열 안 가르켜서 ㅋㅋ 
		ArrCount = _Value; 

	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};

