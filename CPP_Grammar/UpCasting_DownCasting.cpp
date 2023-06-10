#include "pch.h"

//Inheritance Class, UpCasting

class ParentsObject
{
public:

	ParentsObject()
	{
		std::cout << "Parents Constructor.." << std::endl;
	}

	virtual ~ParentsObject() = default;
	

	virtual void Call()
	{
		std::cout << "This is Parents" << std::endl;
	}
};

class Child1 : public ParentsObject
{
public:

	Child1()
	{
		std::cout << "Child1 Constructor.." << std::endl;
	}

	virtual ~Child1()
	{
		std::cout << "Child1 Desctructor.." << std::endl;
	}

	void Call() override
	{
		std::cout << "This is Child1" << std::endl;
	}

	void Child1Fn()
	{
		std::cout << "not virtual type Fn, Child1" << std::endl;
	}
};

class Child2 : public ParentsObject
{
public:


	Child2()
	{
		std::cout << "Child2 Constructor.." << std::endl;
	}

	virtual ~Child2()
	{
		std::cout << "Child2 Desctructor.." << std::endl;
	}

	void Call() override
	{
		std::cout << "This is Child2" << std::endl;
	}

	void Child2Fn()
	{
		std::cout << "not virtual type Fn, Child2" << std::endl;
	}
};


int main(void)
{
	std::vector<std::shared_ptr<ParentsObject>> vec(5);

	// UpCasting Ex.
	for (auto& obj : vec)
	{
		int i = 0;
		std::cin >> i;
		if (i == 1)
		{
			obj = std::make_shared<Child1>();
		}
		else
		{
			obj = std::make_shared<Child2>();
		}
	}

	for (auto& obj : vec)
	{
		obj->Call();
		obj.reset();
	}
	

	//DownCasting Ex.
	std::shared_ptr<ParentsObject> obj = std::make_shared<Child1>();
	//obj->Child1Fn() -> Error

	
	//C++ SmartPointer cast
	std::shared_ptr<Child1> child1_obj = std::dynamic_pointer_cast<Child1>(obj);
	child1_obj->Child1Fn();
	child1_obj.reset();
	
	//C Style Cast
	ParentsObject* child2_obj = new Child2();
	Child2* ptr = dynamic_cast<Child2*>(child2_obj); // (Child2*)(Child2_obj);
	ptr->Child2Fn();

	delete child2_obj;


	return 0;
}