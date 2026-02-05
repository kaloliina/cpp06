#include "ScalarConverter.hpp"

enum types
{
	UNKNOWN,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
};

enum types detectType(std::string ToDetect)
{
	if (ToDetect.length() == 1 && std::isprint(ToDetect[0]))
	{
		std::cout << "we encountered char here..." << std::endl;
		return CHAR;
	}
	if (ToDetect.compare("-inff") == 0 || ToDetect.compare("+inff") == 0 || ToDetect.compare("nanf") == 0 ||
		ToDetect.compare("-inf") == 0 || ToDetect.compare("+inf") == 0 || ToDetect.compare("nan") == 0)
	{
		std::cout << "we encountered something mysterious here..." << std::endl;
		return PSEUDO;
	}
	size_t pos = 0;
	try
	{
		std::stoi(ToDetect, &pos);
		if (ToDetect.length() == pos)
		{
			std::cout << "we encountered int here???" << std::endl;
			return INT;
		}
	}
	catch(const std::out_of_range& e)//triggers with overflow.. //what to return here??
	{
	}
	catch(const std::invalid_argument& e)// .5 should be accepted and treated as double. This approach feels bad but it works for now
	{
		return DOUBLE;
	}
	try
	{
		std::stod(ToDetect, &pos);
		if (ToDetect.length() == pos)
		{
			std::cout << "we encountered double here???" << std::endl;
			return DOUBLE;
		}
	}
	catch(const std::exception& e)
	{
		return UNKNOWN;
	}
	try
	{
		std::stof(ToDetect, &pos); //this allows 60f, 60.f o.o
		if (ToDetect.length() == pos + 1 && ToDetect[pos] == 'f')
		{
			std::cout << "we encountered float here???" << std::endl;
			return FLOAT;
		}
	}
	catch(const std::exception& e)
	{
		return UNKNOWN;
	}
	return UNKNOWN;
}

//robust try catches here??? overflow
//double max, float max
void ScalarConverter::convert(std::string ToConvert)
{
	enum types type;
	type = detectType(ToConvert);
	if (type == CHAR)
	{
		char c = ToConvert[0];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1)<< static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
	}
	else if (type == INT)
	{
		int n = std::stoi(ToConvert);
		if (n < 0 || n > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(n)) //might need impossible check as well! If its like -5
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(n) << std::endl;
		std::cout << "int: " << n << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1)<< static_cast<float>(n) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
	}
	else if (type == FLOAT)
	{
		float n = std::stof(ToConvert);
		if (n < 0 || n > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(n))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char :" << static_cast<char>(n) << std::endl;
		if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;		
		else
			std::cout << "int: " << static_cast<int>(n) << std::endl;			
		std::cout << "float: " << std::fixed << std::setprecision(1) << n << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
	}
	else if (type == DOUBLE) //if input is 1e10...
	{
		double n = std::stod(ToConvert);
		if (n < 0 || n > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(n))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char :" << static_cast<char>(n) << std::endl;
		if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;		
		else
			std::cout << "int: " << static_cast<int>(n) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1)<< static_cast<float>(n) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << n << std::endl;
	}
	else if (type == PSEUDO)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::string fString = ToConvert;
		std::string dString = ToConvert;
		if (ToConvert.compare("-inf") == 0 || ToConvert.compare("+inf") == 0 || ToConvert.compare("nan") == 0)
			fString.append("f");
		else
			dString.pop_back();
		std::cout << "float: " << fString << std::endl;
		std::cout << "double: " << dString << std::endl;
	}
}

//what should 0 be, that shouldnt be char or should it? mby the char check needs like a if its not num
//tab?
//overflows
//is .42 "acceptable"
int main(int argc, char *argv[])
{
//argc check and make it non instantiable...
ScalarConverter::convert(argv[1]);
}