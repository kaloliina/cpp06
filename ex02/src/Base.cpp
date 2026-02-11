#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <exception>

//https://www.geeksforgeeks.org/cpp/casting-operators-in-cpp/ useful info
Base*	Base::generate(void)
{
	Base* obj = nullptr;
	std::srand(std::time(nullptr));
	if ((rand() % 3) == 0)
	{
		std::cout << "Creating A" << std::endl;
		obj = new A();
	}
	else if ((rand() % 3) == 1)
	{
		std::cout << "Creating B" << std::endl;
		obj = new B();
	}
	else
	{
		std::cout << "Creating C" << std::endl;
		obj = new C();
	}
	return obj;
}

/*In pointer conversions, dynamic_cast simply returns a null pointer*/
void	Base::identify(Base* p)
{
	std::cout << "We've encountered a pointer" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C" << std::endl;
	else
		std::cout << "Cannot identify type" << std::endl;
}

/*For reference conversions, dynamic_cast throws a bad_cast exception*/
void	Base::identify(Base& p)
{
	std::cout << "We've encountered a reference" << std::endl;
	try 
	{
		(void)dynamic_cast<A&>(p); //adding (void), otherwise -Werror triggers
		std::cout << "Type is A" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e)
	{
	}
	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type is B" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e)
	{
	}
	try 
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type is C" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e)
	{
	}
}
