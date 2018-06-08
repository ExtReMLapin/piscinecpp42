#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(11);
	v1.push_back(125);
	std::cout << (easyfind(v1, 11)) << std::endl;
	std::cout << (easyfind(v1, 125)) << std::endl;
	
	try {
		std::cout << (easyfind(v1, -1)) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	


	std::cout << "------" << std::endl;
	std::list<float> v2;
	v2.push_back(0);
	v2.push_back(33);
	std::cout << (easyfind(v2, 0)) << std::endl;
}