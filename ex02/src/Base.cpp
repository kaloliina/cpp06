#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <iostream>
#include <ctime>

Base*	Base::generate(void)
{
	Base* obj = nullptr;
	std::srand(std::time(nullptr));
	if ((rand() % 3) == 0)
		obj = new A();
	else if ((rand() % 3) == 1)
		obj = new B();
	else
		obj = new C();
	return obj;
}

/*Dynamic_cast operator is mainly used to perform downcasting
(converting a pointer/reference of a base class to a derived class)
in polymorphisms and inheritance. It ensures type safety by performing
a runtime check to verify the validity of the conversion.
dynamic_cast<new_type>(exp)

If the conversion is not possible, dynamic_cast returns a null pointer
for pointer conversions.*/
void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C" << std::endl;
	else
		std::cout << "Cannot identify type" << std::endl;
}

/*If the conversion is not possible, dynamic_cast throws a bad_cast exception
for reference conversions.*/
void	Base::identify(Base& p)
{
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
