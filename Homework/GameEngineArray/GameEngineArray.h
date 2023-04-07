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
	{ // ���� 3. �� ����(�ϴ� 2��) // = ����Ʈ ���� �����ڷ� ���� ���� ���簡 �Ǿ��� ����. 
		//ArrCount = _Other.ArrCount;
		//ArrPtr = _Other.ArrPtr;

		// �ذ���: ���� ���簡 �̷�������� ��������ڸ� ���Ӱ� �������ش�.(�����ϴ� �޸𸮵� �����ؾ���) 
		// 3. ReSize �Լ��� �ۿ�: ������ �޸𸮸� ���Ӱ� ����. 

		ReSize(_Other.ArrCount); // 1. ����� ũ��� �������� �Ѵ�. 

		for (size_t i = 0; i < _Other.ArrCount; i++) // 2.�迭 ä��� ��, �׷��� Ŭ���� GameEngineArray& operator=(const GameEngineArray& _Other) 
													//�� const�̹Ƿ� ȣ�Ⱑ���� ����Լ��� const ��. ���� �Ʒ� operator�� const�� �ٿ���. 
		{

			ArrPtr[i] = _Other[i]; 
		}


		return *this;
	}
	// ���� ���縦 ���� ���簡 �ǵ��� �ٲ��ִ� ��������. ���� 3 �ذ� -> �׷��� �޸� ������ �߻�. (������ 1,2Ǯ���� ����)_ 

	size_t Count() 
	{
		return ArrCount; // �̰Թ迭�� ũ�� 
	}

	DataType& operator[](size_t _Index) const 
	{
		return ArrPtr[_Index];
	}

	//����1: resize() �۵� ��, �����Ⱚ ��� ���� �迭�� �޸𸮰� ���Եǵ��� �ذ�. 
	//��Ʈ: ���׿����� ���, ������ �ִ� ������ ������ �迭�� �����Ѵ��� �����ؾ� �Ѵ�.
	void ReSize(int _Value) // ��������� �迭�� ũ�Ⱑ �μ���. _Value
	{
		//a. ���� �迭�� �Ҵ���� �� �迭 ����. 
		int* newArrPtr = nullptr;

		//b. �迭 newArrPtr�� ũ��� ����� ���� ����. 
		int newResizeCount = 0; // 

		//c. �迭 newArrPtr�� ũ��(newResizeCount)�� ���� �迭�� ũ��(ArrCount)�� ��.
		// newResizeCount>ArrCount ��� _Value(=Resize �� �迭�� ũ��)�� ���. newResizeCount<ArrCount ��� ArrCount�� ���. 

		if (_Value > ArrCount)// 5 > 10
		{
			newResizeCount = _Value; 
		}
		else
		{
			newResizeCount = ArrCount; // Arrcount�� �׳� ���ٴ� ��. ArrCo
		}

		// ���׿����ڷ� �����: 
		// _Value > ArrCount ? newResizeCount = _Value : newResizeCount = ArrCount; �̰� �ƴ϶� 
		// newResizeCount = _Value > ArrCount ? _Value : ArrCount;  �̷��� ������ �� 
		// newResizeCount = (_Value > ArrCount ? _Value : ArrCount);  �̷��� ��ȣ �־ int��� �����ϸ� ��. ���ϰ��� int�ϱ�. 
		// ��:  _Value > ArrCount�� true�Ͻ�, ���� _Value�� newResizeCount�� ����. false�Ͻ� ArrCount�� �����Ѵٴ� ��. 

		/// a~c�� �� �迭�� �����ϰ� �� �迭�� ũ�⸦ ������ ������ ���ϴ� ����. 

		//d. a���� ������ ���ο� �迭 newArrPtr�� ���� �����Ҵ�. 
		newArrPtr = new int[newResizeCount];  // ���� [n] ũ���� �迭�� ���� �� �� �̸��� newArrPtr�� �ٿ���. 

		//e. ������ �Ҵ�� �迭��(ex.Array0) ���ο� �迭 newArrPtr�� ���� & ���� ����. 
		for (int i = 0; i < newResizeCount; i++) 
		{
			newArrPtr[i] = ArrPtr[i];  
		}


		//f. newAttPtr�� ������ Array0�� ���縦 Ȯ��. ���� ArrPtr�� ����Ű�� arr0�� ������ delete�Ѵ�. 
		// **������ �Ҵ�� �迭�� �˰� �ִ°��� ���Ҹ� ����� �ȵȴ�.** 

		// --- ������ Ǯ�� 1,2�� ������ ���⼭ ������ --- // 

		if (nullptr != ArrPtr)  
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		//g. ������ ArrPtr�� ���ο� �迭 newArrPtr�� ����Ŵ. 
		ArrPtr = newArrPtr;  // ������ Ǯ�� �� �߻� ����. ���ο� �迭 �� �����Ѽ� ���� 
		ArrCount = _Value; 

	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};

