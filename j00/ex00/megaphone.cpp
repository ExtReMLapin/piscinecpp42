#include <iostream>

int main(int argc, char const **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int i = 1;
	while (i < argc)
	{
		int i2 = 0;
		while (argv[i][i2])
		{
			std::cout << (char)std::toupper(argv[i][i2]);
			i2++;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}
