#include <string>
#include <iostream>
#include <limits>
#include  <cctype>

#include <cstdlib>
bool isChar = false;
bool isInt = false;
bool isDouble = false;
bool isFloat = false;


std::string data;

static size_t leng(std::string str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}


static bool islower(char c)
{
	return (c <= 'z' && c >= 'a');
}

static bool isDigit(char c)
{
	return (c <= '9' && c >= '0'); 
}

static bool isPrint(int c)
{
	return (c > 31 && c < 127);
}

static std::string substr(std::string str, size_t pos, size_t len)
{
	std::string ret = "";

	size_t i = 0;
	while (i < len)
		ret += str[pos+i++];
	return (ret);
}




bool selecttype()
{
	bool hasDot = false;
	bool hasF = false;
	bool hasNum = false;
	if (leng(data) == 1 && islower(data[0]))
	{	
		return true;
	}

	if (data == "-inff" || data == "inff" || data == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << data  << std::endl;
		std::cout << "double: " << substr(data, 0, leng(data)-1)  << std::endl;
		return true;
	}

	if (data == "-inf" || data == "inf" || data == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << data << 'f' << std::endl;
		std::cout << "double: " << data << std::endl;
		return true;
	}

	unsigned long i = 0;
	while (data[i])
	{
		char c = data[i];
		if (isDigit(c))
			hasNum = true;
		else if (c == '.')
		{
			if (hasDot || hasF)
				return false; // double dot
			if (c == 0 || i == leng(data)-1) // dot at start or end, alone
				return false; 
			if (data[i+1] == 'f')
				return false; // something like  .f which is wrong
			hasDot = true;
		}
		else if (c == 'f')
		{
			if (i != leng(data)-1) // f not at the end, fail
				return false;
			hasF = true;
		}
		else if (c == '-')
		{
			if (i != 0)
				return false; // - is not at the start
		}
		else
			return false;
		i++;
	}
	if (hasNum == false)
		return false;
	if (hasDot == false && hasF == false)
	{
		signed int num = std::atoi( data.c_str() );
		std::cout << "char: ";
		if (isPrint(num))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

		std::cout << "int: " << num << std::endl;
		std::cout << "float: " << static_cast<float>(num) << std::endl;
		std::cout << "double: " << static_cast<float>(num) << std::endl;
		return true;
	}
	else if(hasDot == true && hasF == false)
	{
		signed int num = std::atoi( data.c_str() );
		std::cout << "char: ";
		if (isPrint(num))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << num << std::endl;
		std::cout << "float: " << data << 'f' << std::endl;
		std::cout << "double: " << data << std::endl;
		return true;
	}
	else if(hasDot == true && hasF == true)
	{
		std::string data_minus_f = substr(data, 0, leng(data)-1);
		signed int num;
		num = std::atoi( data_minus_f.c_str() );
		std::cout << "char: ";
		if (isPrint(num))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << num << std::endl;
		std::cout << "float: " << data  << std::endl;
		std::cout << "double: " << data_minus_f << std::endl;
		return true;
	}
	else if(hasDot == false && hasF == true)
	{
		std::string data_minus_f = substr(data, 0, leng(data)-1);
		double num = std::atoi( data_minus_f.c_str() );
		std::cout << "char: ";
		if (isPrint(num))
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << num << std::endl;
		std::cout << "float: " << data  << std::endl;
		std::cout << "double: " << data_minus_f << std::endl;
		return true;
	}

	return (false);
}


int main(int agc, char ** argv)
{
	if (agc != 2)
	{
		std::cout << "1 arg only pls" << std::endl;
		return (1);
	}
	data = argv[1];
	if (!selecttype())
		std::cout << "Parsing failed" << std::endl;
	return(0);

}