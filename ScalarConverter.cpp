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

//I want to take whatever data type here??? mby templates
//void convertToRest()

enum types detectType(std::string ToDetect)
{
	if (ToDetect.length() == 1 && std::isalpha(ToDetect[0]))
	{
		std::cout << "we encountered char here..." << std::endl;
		return CHAR;
	}
	if (ToDetect.compare("-inff") == 0 || ToDetect.compare("+inff") == 0 || ToDetect.compare("nanf") == 0 ||
		ToDetect.compare("-inf") == 0 || ToDetect.compare("+inf") == 0 || ToDetect.compare("nan") == 0)
	{
		//we might need to divide this into double and float pseudo
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
	catch(const std::exception& e)
	{
		std::cout << "ERROR1" << std::endl;
		//this is what recognizes overflow .. 8)
		std::cerr << e.what() << '\n';
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
		std::cout << "ERROR2" << std::endl;
		std::cerr << e.what() << '\n';
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
		std::cout << "ERROR3" << std::endl;
		std::cerr << e.what() << '\n';
	}
	return UNKNOWN;
}

void ScalarConverter::convert(std::string ToConvert)
{
	//we may still need to convert them really because it says convert them explicitly
	enum types type;
	type = detectType(ToConvert);
	if (type == CHAR)
	{
		std::cout << "char: " << ToConvert << std::endl;
		std::cout << "int: " << (int)ToConvert[0] << std::endl;
		//float and double
	}
	else if (type == INT)
	{
		//check for overflow....
		int data = std::stoi(ToConvert);
		std::cout << "Converted: " << data << std::endl;
		if (!std::isprint(data))
		{
			std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char :" << (char)data << std::endl;
		std::cout << "int: " << data << std::endl;
		float data1 = static_cast<float>(data); //not working
		std::cout << "float: " << data1 << std::endl;
		double data2 = static_cast<double>(data); // not working
		std::cout << "double: " << data2 << std::endl;
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
	//float and double missing
	//detect the type
	//convert it to its actual type
	//then convert it to the other three data types

}

int main(int argc, char *argv[])
{
//argc check and make it non instantiable...
std::cout << "here..." << std::endl;
ScalarConverter::convert(argv[1]);
}





// //I want to take whatever data type here??? mby templates
// //void convertToRest()

// enum types detectType(std::string ToDetect)
// {
// 	int digit = 0;
// 	if (ToDetect.length() == 1 && std::isalpha(ToDetect[0]))
// 	{
// 		std::cout << "we encountered char here..." << std::endl;
// 		return CHAR;
// 	}
// 	for (char c : ToDetect)
// 	{
// 		if (std::isdigit(c))
// 			digit++;
// 	}
// 	if (ToDetect.length() == digit)
// 	{
// 		std::cout << "we encountered int here..." << std::endl;
// 		return INT;
// 	}
// 	if (ToDetect.compare("-inff") == 0 || ToDetect.compare("+inff") == 0 || ToDetect.compare("nanf") == 0 ||
// 		ToDetect.compare("-inf") == 0 || ToDetect.compare("+inf") == 0 || ToDetect.compare("nan") == 0)
// 	{
// 		//we might need to divide this into double and float pseudo
// 		std::cout << "we encountered something mysterious here..." << std::endl;
// 		return PSEUDO;
// 	}
// 	//we need to detect float and double as well
// 	return UNKNOWN;
// }
