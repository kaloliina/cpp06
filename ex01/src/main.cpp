#include "../include/Serializer.hpp"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	Data datuliini;
	datuliini.years_since_bought = 5;
	datuliini.brand = "Helmut Lang";

	std::cout << &datuliini << std::endl;
	uintptr_t ptr;
	Data* ptr1;

	ptr = Serializer::serialize(&datuliini);
	std::cout << ptr << std::endl;
	ptr1 = Serializer::deserialize(ptr);
	std::cout << ptr1 << std::endl;
	return 0;
}
