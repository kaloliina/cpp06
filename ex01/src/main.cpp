#include "../include/Serializer.hpp"

int main(void)
{
	Data datuliini;
	datuliini.years_since_bought = 5;
	datuliini.brand = "Nike";

	std::cout << &datuliini << std::endl;
	uintptr_t ptr;
	Data* ptr1;

	ptr = Serializer::serialize(&datuliini);
	std::cout << ptr << std::endl;
	ptr1 = Serializer::deserialize(ptr);
	std::cout << ptr1 << std::endl;
	return 0;
}
