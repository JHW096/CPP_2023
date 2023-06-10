#include "pch.h"
// Member Init List
// Copy, Move Constructor
// Quote Microsoft Document
class Object
{
public:
	//Simmple Constructor
	Object(size_t Size) :
		m_Size{ Size },
		m_Data(new int[Size])
	{
		std::cout << "Simple Constructor, Size : " << m_Size << std::endl;
	}

	//Copy Constructor
	Object(const Object& _Other) :
		m_Size{ _Other.m_Size },
		m_Data{ _Other.m_Data }
	{
		std::cout << "Copy Constructor, Size : " << m_Size << std::endl;
	}

	//Copy Assignment Operator
	Object& operator=(const Object& _Other)
	{
		std::cout << "Copy Assignment, Size : " << _Other.m_Size << std::endl;

		if (this != &_Other)
		{
			delete[] m_Data;

			m_Size = _Other.m_Size;
			m_Data = new int[m_Size];
			std::copy(_Other.m_Data, _Other.m_Data + m_Size, m_Data);
		}
		return *this;
	}

	//Move Constructor
	Object(Object&& _Other) noexcept
		: m_Size{ 0 },
		  m_Data{ nullptr }
	{
		std::cout << "Move Constructor" << std::endl;
		*this = std::move(_Other);
	}

	//Move Assignment Operator
	Object& operator=(Object&& _Other) noexcept
	{
		/*
			이 객체가 _Other와 다르다면,
			- delete Data. 
			- 이 객체의 맴버 변수를 Other로 복사.
			- Other의 멤버 변수를 초기화 및 포인터 해제
		*/
		
		if (this != &_Other)
		{
			delete[] m_Data;

			m_Size = _Other.m_Size;
			m_Data = _Other.m_Data;

			_Other.m_Size = 0;
			_Other.m_Data = nullptr;
		}
		return *this;
	}

	//Desctructor
	~Object()
	{
		std::cout << "Destructor" << std::endl;
	}

	size_t GetSize()
	{
		return this->m_Size;
	}
private:
	size_t m_Size;
	int* m_Data;
};

int main(void)
{
	std::vector<Object> objs;
	objs.reserve(4);

	Object Simple(5);
	Object Copy(9);

	Simple = Copy;

	objs.emplace_back(Simple);
	objs.emplace_back(Object(7));


	
	

	return 0;
}