#include "../include/Base.hpp"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	Base* base = nullptr;
	base = base->generate();
	base->identify(base);
	base->identify(*base);
	delete base;
	return 0;
}
