#include <iostream>

typedef int DataType;

// ���� :
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

	//����1: resize() �۵� ��, �����Ⱚ ��� ���� �迭�� �޸𸮰� ���Եǵ��� �ذ�. 
	//��Ʈ: ���׿����� ���, ������ �ִ� ������ ������ �迭�� �����Ѵ��� �����ؾ� �Ѵ�.
	void ReSize(int _Value) 
	{
		//a. ���� �迭�� �Ҵ���� �� �迭 ����. 
		int* newArrPtr = nullptr;

		//b. �迭 newArrPtr�� ũ��� ����� ���� ����. 
		int newResizeCount = 0;

		//c. �迭 newArrPtr�� ũ��(newResizeCount)�� ���� �迭�� ũ��(ArrCount)�� ��.
		// newResizeCount>ArrCount ��� _Value(=Resize �� �迭�� ũ��)�� ���. newResizeCount<ArrCount ��� ArrCount�� ���. 

		if (_Value > ArrCount)
		{
			newResizeCount = _Value; 
		}
		else
		{
			newResizeCount = ArrCount; 
		}

		// ���׿����ڷ� �����: 
		// _Value > ArrCount ? newResizeCount = _Value : newResizeCount = ArrCount;

		//d. a���� ������ ���ο� �迭 newArrPtr�� ���� �����Ҵ�. 
		newArrPtr = new int[newResizeCount];  

		//e. ������ �Ҵ�� �迭��(ex.Array0) ���ο� �迭 newArrPtr�� ���� & ���� ����. 
		for (int i = 0; i < newResizeCount; i++) 
		{
			newArrPtr[i] = ArrPtr[i];  
		}

		//f. newAttPtr�� ������ Array0�� ���縦 Ȯ��. delete. 
		if (nullptr != ArrPtr) // **������ �Ҵ�� �迭�� �˰� �ִ°��� ���Ҹ� ����� �ȵȴ�.** 
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		//g. ������ ArrPtr�� ���ο� �迭 newArrPtr�� ����Ŵ. 
		ArrPtr = newArrPtr;  
		ArrCount = _Value; 

	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};

