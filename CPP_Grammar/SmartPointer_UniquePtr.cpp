#include "pch.h"

//Exclusive Ownership Pointer : Unique_Ptr;

class Test
{
public:
	Test()
	{
		std::cout << "Constructor.." << std::endl;
	}

	~Test()
	{
		std::cout << "destructor.." << std::endl;
	}
};

void TestFn()
{
	std::cout << "Function Push Stack" << std::endl;
	std::unique_ptr<Test> _test = std::make_unique<Test>();
	std::cout << "Function Pop Stack" << std::endl;
}

void TestFn2()
{
	std::cout << "Function Push Stack" << std::endl;
	Test* test = new Test();
	std::cout << "Function Pop Stack" << std::endl;
}


int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	

	
	std::unique_ptr<int> ptr0 = std::make_unique<int>(10);
	//std::unique_ptr<int> ptr1 = ptr0; : Error
	std::unique_ptr<int> ptr1 = std::move(ptr0); 

	//새로운 Unique_ptr로는 옮길 수 없고,
	//std::move로 기존 연결을 끊고 새로운 unqiue_ptr에 연결 할 수 있다.
	std::cout << ptr0.get() << std::endl; //-> nullptr
	std::cout << ptr1.get() << std::endl;

	std::cout << std::endl;

	//Smart Pointer는 스코프(중괄호)를 넘어가면 자동으로 해제된다.
	//그래도 혹시모르니 Release함수를 쓰는 습관을 들이도록하자.
	TestFn();
	/*
		Use Smart Pointer Result.

		- Push
		- Constructor
		- Pop
		- Desctructor
	*/

	std::cout << std::endl;

	TestFn2();
	/*
		Use Traditional Pointer Result.
		
		- Push
		- Constructor
		- Pop
		
		"Memory Leak"
	*/

}