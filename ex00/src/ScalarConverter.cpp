#include "../include/ScalarConverter.hpp"

/*
- How to deal with helper functions that are related to a specific class?
*/
enum types
{
	UNKNOWN,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
};

enum types detectType(std::string ToDetect) //Polish this
{
	if (ToDetect.length() == 1 && std::isprint(ToDetect[0]) && !std::isdigit(ToDetect[0])) //Double check this, if input is digit(0-9), we consider it as an int?
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
	catch(const std::exception& e)//triggers out of range and invalid argument (.5) but at that point, we still want to proceed because it is valid
	{
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
	catch(const std::exception& e) //when would this realistically fail since most issues are caught in stod's catch?
	{
		std::cout << "we are here when we give float max, why?" << std::endl;
		return UNKNOWN;
	}
	return UNKNOWN;
}

/*Static_cast performs compile-time type conversion and is mainly used for explicit conversions.
static_cast<new_type>(exp)
- exp: Data to be converted
- new_type: Desired type of expression
Static_cast can be used to convert between related types.

We have converted the data to double as double can hold most amount of data.
std::fixed tells how to display(fixed-point, includes decimals) and std::setprecision
tells how many decimals to show.*/
void printRegular(double ToConvert)
{
	/*char*/
	if (ToConvert < 0 || ToConvert > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(ToConvert))
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

void printPseudo(enum types type, std::string ToConvert)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (type == PSEUDO)
	{
		std::string fString = ToConvert;
		std::string dString = ToConvert;
		if (ToConvert.compare("-inf") == 0 || ToConvert.compare("+inf") == 0 || ToConvert.compare("nan") == 0)
			fString.append("f");
		else
			dString.pop_back();
		std::cout << "float: " << fString << std::endl;
		std::cout << "double: " << dString << std::endl;
	}
	else if (type == UNKNOWN)
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;	
	}
}

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
		printRegular(result);
	else
		printPseudo(type, ToConvert);
}
