#include <string>
#include <iostream>

int main(void)
{
	std::string str =  "HI THIS IS BRAIN";

	std::string *string = &str;
	std::string &strring = *string;

	std::cout << *string << std::endl << strring << std::endl;

}