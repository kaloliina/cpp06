#include "../include/ScalarConverter.hpp"

//what should 0 be, that shouldnt be char or should it? mby the char check needs like a if its not num
//tab?
//overflows
//is .42 "acceptable"
//tests...
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Expected format: ./ScalarConverter <String to Convert>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
