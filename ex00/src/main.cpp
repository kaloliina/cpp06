#include "../include/ScalarConverter.hpp"

void tests()
{
	std::cout << "CHAR" << std::endl;
	ScalarConverter::convert("a");
	ScalarConverter::convert("*");
	ScalarConverter::convert("~");
	ScalarConverter::convert("\n");
	std::cout << "\n";
	std::cout << "INT" << std::endl;
	ScalarConverter::convert("+48");	
	ScalarConverter::convert("30");
	ScalarConverter::convert("8");
	ScalarConverter::convert("127");
	ScalarConverter::convert("-128");
	ScalarConverter::convert("2147483647");
	ScalarConverter::convert("-2147483648");
	ScalarConverter::convert("2147483648");
	std::cout << "\n";
	std::cout << "FLOAT" << std::endl;
	ScalarConverter::convert("30.0f");
	ScalarConverter::convert("-0.5f");
	ScalarConverter::convert(".5f");
	ScalarConverter::convert("42.f");
	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::lowest()));
	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::max()));
	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::lowest() * 1.5));
	ScalarConverter::convert(std::to_string(std::numeric_limits<float>::max() * 1.5));
	std::cout << "\n";
	std::cout << "DOUBLE" << std::endl;
	ScalarConverter::convert("30.0");
	ScalarConverter::convert("-0.5");
	ScalarConverter::convert(std::to_string(std::numeric_limits<double>::lowest()));
	ScalarConverter::convert(std::to_string(std::numeric_limits<double>::max()));
	std::cout << "\n";
	std::cout << "PSEUDO" << std::endl;
	ScalarConverter::convert("nan");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inff");
	std::cout << "\n";
	std::cout << "UNKNOWN" << std::endl;
	ScalarConverter::convert("abc");
	ScalarConverter::convert("30..0");
	ScalarConverter::convert("++30");
	ScalarConverter::convert("20..");
	ScalarConverter::convert("20.F");
	std::cout << "\n";
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Expected format: ./ScalarConverter <String to Convert>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
//	(void)argc;
//	(void)argv;
//	tests();
	return 0;
}
