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
	{
		ArrCount = _Other.ArrCount;
		ArrPtr = _Other.ArrPtr;
		return *this;
	}

	size_t Count() 
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	//숙제1: resize() 작동 시, 쓰레기값 대신 기존 배열의 메모리가 대입되도록 해결. 
	//힌트: 삼항연산자 사용, 기존의 있던 값에서 현재의 배열이 복사한다음 삭제해야 한다.
	void ReSize(int _Value) 
	{
		//a. 기존 배열을 할당받을 빈 배열 선언. 
		int* newArrPtr = nullptr;

		//b. 배열 newArrPtr의 크기로 사용할 변수 선언. 
		int newResizeCount = 0;

		//c. 배열 newArrPtr의 크기(newResizeCount)와 현재 배열의 크기(ArrCount)를 비교.
		// newResizeCount>ArrCount 라면 _Value(=Resize 된 배열의 크기)를 사용. newResizeCount<ArrCount 라면 ArrCount를 사용. 

		if (_Value > ArrCount)
		{
			newResizeCount = _Value; 
		}
		else
		{
			newResizeCount = ArrCount; 
		}

		// 삼항연산자로 선언시: 
		// _Value > ArrCount ? newResizeCount = _Value : newResizeCount = ArrCount;

		//d. a에서 선언한 새로운 배열 newArrPtr을 힙에 동적할당. 
		newArrPtr = new int[newResizeCount];  

		//e. 기존의 할당된 배열을(ex.Array0) 새로운 배열 newArrPtr에 복사 & 값을 보존. 
		for (int i = 0; i < newResizeCount; i++) 
		{
			newArrPtr[i] = ArrPtr[i];  
		}

		//f. newAttPtr에 기존의 Array0의 복사를 확인. delete. 
		if (nullptr != ArrPtr) // **기존의 할당된 배열을 알고 있는것은 섣불리 지우면 안된다.** 
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		//g. 포인터 ArrPtr가 새로운 배열 newArrPtr을 가리킴. 
		ArrPtr = newArrPtr;  
		ArrCount = _Value; 

	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};

