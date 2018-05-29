#pragma once

#include <string>

class Pony{

public:
	bool isDebile;
	uint32_t color;
	std::string nom;

	~Pony();
	Pony();
	void check(int *i);

private:
	std::string criniere; // pas touche !!
};
