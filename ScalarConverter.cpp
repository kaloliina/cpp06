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
	if (ToDetect.length() == 1 && std::isprint(ToDetect[0])) //do we need a check if its not a number???
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
	catch(const std::exception& e)//triggers out of range and invalid argument (.5) but we actually want to proceed at that point
	{
	}
	try //better to try catch here or inn the convert? feels redundant to do it in both
	{
		std::stod(ToDetect, &pos);
		if (ToDetect.length() == pos)
		{
			std::cout << "we encountered double here???" << std::endl;
			return DOUBLE;
		}
	}
	catch(const std::exception& e) //this triggers with invalid input, big overflow etc. 
	{
		std::cout << "we are here when we give double max, why?" << std::endl;
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
		std::cout << "we are here when we give float max, why?" << std::endl;
		return UNKNOWN;
	}
	return UNKNOWN;
}


void printResult(enum types type, double ToConvert)
{
	/*char*/
	if (ToConvert < 0 || ToConvert > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(ToConvert)) //might need impossible check as well! If its like -5
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(ToConvert) << std::endl;
	/*int*/
	if (ToConvert > std::numeric_limits<int>::max() || ToConvert < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;		
	else
		std::cout << "int: " << static_cast<int>(ToConvert) << std::endl;
	/*float*/
	if (ToConvert > std::numeric_limits<float>::max() || ToConvert < std::numeric_limits<float>::min())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1)<< static_cast<float>(ToConvert) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << ToConvert << std::endl;
}

/*there are some cases where instead of float, we return double in detectType, it's actually working but maybe by accident*/
void ScalarConverter::convert(std::string ToConvert)
{
	enum types type;
	type = detectType(ToConvert);
	double result;
	if (type == CHAR)
		result = ToConvert[0];
	if (type == INT || type == FLOAT || type == DOUBLE)
		result = stod(ToConvert);
	if (type == CHAR || type == INT || type == FLOAT || type == DOUBLE)
	{
		printResult(CHAR, result);
	}
	else if (type == PSEUDO) //separate function for this?
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
	else if (type == UNKNOWN) //separate function for this???
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;	
	}
}

//what should 0 be, that shouldnt be char or should it? mby the char check needs like a if its not num
//tab?
//overflows
//is .42 "acceptable"
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
