#include "pch.h"
//R-Value (Variable) / L-Value (Literal)

class Object
{
public:
	Object()
	{
		std::cout << "Constructor" << std::endl;
	}

	~Object()
	{
		std::cout << "Destructor" << std::endl;
	}

	std::string GetName()
	{
		return m_Name;
	}

	void NameClear()
	{
		m_Name.clear();
	}
	
	//if u insert R-Value, 0 Copy
	void SetName0(std::string _Name)
	{
		m_Name = std::move(_Name);
	}

	//1Copy
	void SetName1(const std::string& _Name)
	{
		//Visual Studio가 Const Type에 Move를 쓰는 것을 추천하지 않음.
		m_Name = std::move(_Name);
	}

	void SetName2(std::string&& _Name)
	{
		m_Name = _Name;
	}

private:
	std::string m_Name;
};

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	Object obj;
	std::string str = "Object";

	obj.SetName0(str);			// 1Copy
	obj.SetName0("Object");		// 0Copy
	obj.NameClear();

	obj.SetName1(str);			// 1Copy
	obj.SetName1("Object");		// 1Copy
	obj.NameClear();


	//obj.SetName2(str);		// Complie Error : SetName2 can not receive L-Value.
	obj.SetName2("Object");		// 1Copy, Ownership not changed


	/*
	R - Value, L - Value를 둘다 적용시킬 수 있으며,
	R - Value Reference의 의도대로 Copy가 일어나지 않으려면,
	SetName0() 함수를 만든다.
	*/
	return 0;
}