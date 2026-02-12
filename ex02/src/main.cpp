#include "../include/Base.hpp"

int main(void)
{
	Base* base = nullptr;
	base = generate();
	base->identify(base);
	base->identify(*base);
	delete base;
	return 0;
}
