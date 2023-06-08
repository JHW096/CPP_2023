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
};

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//Shared Ownership Pointer
	
	std::shared_ptr<Object> Ptr0 = std::make_shared<Object>();
	std::shared_ptr<Object> Ptr1 = Ptr0;
	std::shared_ptr<Object> Ptr2 = Ptr1;
	
	std::cout << Ptr0.use_count() << std::endl; //3

	Ptr0.reset();								
	std::cout << Ptr0.use_count() << std::endl; //0
	std::cout << Ptr1.use_count() << std::endl; //2 (Ptr1, Ptr2)
	{
		Ptr1.reset();							//1
		Ptr2.reset();							//0
		//Expected Result -> Dectructor
		std::cout << "All Pointer Reset, Scope Out" << std::endl;
	}

	return 0;
}