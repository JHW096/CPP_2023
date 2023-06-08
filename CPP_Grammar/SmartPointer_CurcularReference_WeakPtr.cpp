#include "pch.h"

class Object
{
public:
	Object()
	{
		std::cout << "Constructor.." << std::endl;
	}

	~Object()
	{
		std::cout << "Desctructor.." << std::endl;
	}

public:
	std::shared_ptr<Object> m_Friend;
};

class Object2
{
public:
	Object2()
	{
		std::cout << "Constructor.." << std::endl;
	}

	~Object2()
	{
		std::cout << "Desctructor.." << std::endl;
	}

public:
	std::weak_ptr<Object2> m_Friend;
};

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//Shared Pointer Curcular Reference, Weak Ptr
	
	std::shared_ptr<Object> obj1 = std::make_shared<Object>();
	std::shared_ptr<Object> obj2 = std::make_shared<Object>();

	obj1->m_Friend = obj2;
	obj2->m_Friend = obj1;
	/*
		Result
		- Constructor : 2
		- Destructor  : 0
		각자의 멤버변수인 m_Friend가 서로를 가르켜 Reference Count가 0이 되지 않아서이다.
	*/


	std::shared_ptr<Object2> obj_1 = std::make_shared<Object2>();
	std::shared_ptr<Object2> obj_2 = std::make_shared<Object2>();

	obj_1->m_Friend = obj_2;
	obj_2->m_Friend = obj_1;
	/*
		Result
		- Constructor : 2
		- Desctructor : 2 
	*/
	return 0;
}