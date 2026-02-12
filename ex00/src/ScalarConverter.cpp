#include "../include/ScalarConverter.hpp"

enum types
{
	UNKNOWN,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
};

/*
- First we detect CHAR
- Then we detect PSEUDO (Positive/Negative Infinity, Not a Number...)
- stoi to recognize INT. pos tells how many characters were parsed, if pos matches length, then we know it's INT.
If stoi throws (invalid argument, out of range), we still proceed, because it might be a valid double or float!
- Then stod to recognize double. If this throws, then we know the input is invalid (out of range...) and return unknown.
However, if length does not match the pos, we may still proceed to recognize possible float with stof.
Then we check if length equals to pos + 1 (+1 for the float) and if the last char is f, to return float.
*/
static enum types detectType(std::string ToDetect)
{
	if (ToDetect.length() == 1 && !std::isdigit(ToDetect[0]))
		return CHAR;
	if (ToDetect.compare("-inff") == 0 || ToDetect.compare("+inff") == 0 || ToDetect.compare("nanf") == 0 ||
		ToDetect.compare("-inf") == 0 || ToDetect.compare("+inf") == 0 || ToDetect.compare("nan") == 0)
		return PSEUDO;
	size_t pos = 0;
	try
	{
		std::stoi(ToDetect, &pos);
		if (ToDetect.length() == pos)
			return INT;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		std::stod(ToDetect, &pos);
		if (ToDetect.length() == pos)
			return DOUBLE;
	}
	catch(const std::exception& e)
	{
		return UNKNOWN;
	}
	try
	{
		std::stof(ToDetect, &pos);
		if (ToDetect.length() == pos + 1 && ToDetect[pos] == 'f')
			return FLOAT;
	}
	catch(const std::exception& e)
	{
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
tells how many decimals to show.

Psst. Sometimes numbers change and you get precision loss when converting from int
to float because float can't represent all integers exactly so it rounds
to the nearest value.
*/
static void printRegular(double ToConvert)
{
	/*char*/
	if (ToConvert < 0 || ToConvert > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(ToConvert))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(ToConvert) << std::endl;
	/*int*/
	if (ToConvert > std::numeric_limits<int>::max() || ToConvert < std::numeric_limits<int>::lowest())
		std::cout << "int: impossible" << std::endl;		
	else
		std::cout << "int: " << static_cast<int>(ToConvert) << std::endl;
	/*float*/
	if (ToConvert > std::numeric_limits<float>::max() || ToConvert < std::numeric_limits<float>::lowest())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1)<< static_cast<float>(ToConvert) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << ToConvert << std::endl;
}

static void printPseudo(enum types type, std::string ToConvert)
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
	std::cout << "\nInput received: " << ToConvert << std::endl;
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
