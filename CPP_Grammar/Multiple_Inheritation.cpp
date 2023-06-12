#include "pch.h"

//Multiple Inheritation

class A
{
public:
	
	A() { std::cout << "A Constructor.." << std::endl; }

	virtual ~A() { std::cout << "A Destructor.." << std::endl; }

	void AFunction() { std::cout << "A Function.." << std::endl; }

	virtual void VirtualA() { std::cout << "Virtual_A" << std::endl; }

public:
	int m_A;
};

class B
{
public:

	B() { std::cout << "B Constructor.." << std::endl; }

    virtual ~B() { std::cout << "B Desctructor.." << std::endl; }

	void BFunction() { std::cout << "B Function.." << std::endl; }
	
	virtual void VirtualB() { std::cout << "Virtual_B" << std::endl; }
public:
	int m_B;
};

class C : public A, public B
{
public:

	C() { std::cout << "C Constructor.." << std::endl; }
	
	~C() { std::cout << "C Destructor.." << std::endl; }

	void CFunction() { std::cout << "C Function.." << std::endl; }

	void VirtualA() override
	{
		std::cout << "override_A" << std::endl;
	}
	
	void VirtualB() override
	{
		std::cout << "override_B" << std::endl;
	}
public: 
	int m_C;
};


int main(void)
{
	/*
		C TestC;
		Make C Instance ->
		Constructor, Destructor Sequence
		- A Constructor
		- B Constructor
		- C Constructor
		- C Destructor
		- B Destructor
		- A Destructor
	*/
	  
	/*
		std::shared_ptr<C> Test = std::make_shared<C>();
		std::cout << sizeof(*Test) << std::endl;		

		None Virtual Destructor Size = 12
		- m_A : 4;
		- m_B : 4;
		- m_C : 4;
	*/

	/*
		Have virtual Desctructor Size = 40;
		- _vfPtr of A : 8
		- m_A : 4 -> 8		(Padding)
		- _vfPtr of B : 8
		- m_B : 4 -> 8		(Padding)
		- m_C : 4 -> 8		(Padding)
	*/


	A* Test = new C;
	std::cout << sizeof(*Test) << std::endl;
	/*
		Size = 16
		- _vfPtr of A : 8
		- m_A : 4
		_ m_C : 4
	*/
	
	C* Test2 = dynamic_cast<C*>(Test);
	std::cout << sizeof(*Test2) << std::endl;
	/*
		Size = 40;
	*/

	delete Test;

	std::shared_ptr<A> Test3 = std::make_shared<C>();
	std::shared_ptr<C> Test4 = std::dynamic_pointer_cast<C>(Test3);
	std::cout << sizeof(Test3) << std::endl;	//Size 16
	std::cout << sizeof(Test4) << std::endl;	//Size 16 이유 모름

	return 0;

}