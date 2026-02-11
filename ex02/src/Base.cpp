#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <ctime>
#include <stdlib.h>
#include <iostream>

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


void	Base::identify(Base& p)
{
	std::cout << "We've encountered a reference" << std::endl;
	if (dynamic_cast<A*>(&p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "Type is C" << std::endl;
	else
		std::cout << "Cannot identify type" << std::endl;
}
