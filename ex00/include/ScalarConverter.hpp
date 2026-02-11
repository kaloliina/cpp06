#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
public:
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter& copy) = delete;
	ScalarConverter& operator=(const ScalarConverter& src) = delete;
	~ScalarConverter() = delete;

	static void	convert(std::string ToConvert);
};
