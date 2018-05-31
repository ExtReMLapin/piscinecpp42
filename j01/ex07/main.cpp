#include <iostream>
#include <fstream>

static std::string 	file_cap(std::string in)
{
	std::string out = "";

	size_t i = 0;

	while (i < in.size())
	{
		out += std::toupper(in[i]);
		i++;
	}
	return out;
}

void	replace(char **argv)
{
	std::string strsource = argv[2]; // pas envie de bosser avec des char*
	std::string strdest = argv[3];
	std::string newfile = file_cap(argv[1]) +  ".replace"; // pas sûr qu'ils voulaient exactement ca mais bon
	std::ifstream	file;// = std::ifstream(argv[1]); // fichier d'entrée InputFileSTREAM
	std::ofstream	file2;// = std::ofstream(newfile); // fichier de sortie OutputFileSTREAM // CA COMPILE PAS
	std::streampos	size;


	file.open(argv[1]);
	if (!file.is_open()) // bein ui
	{
		std::cout << "Error: Unable to open the input file" << std::endl;
		return;
	}

	file2.open(newfile.c_str());
	if (!file2.is_open()) // bein ui
	{
		std::cout << "Error: Unable to open the output file" << std::endl;
		return;
	}

	file.seekg(0, std::ios::end); 
	size = file.tellg(); // comme ici : http://www.cplusplus.com/reference/istream/istream/tellg/

	/*
		En gros on place un "curseur" à la fin du fichier,
		on vérifie sa position pour chopper la taille et on le replace au début
	*/
	std::string	buffer(size, ' '); // pis on refait un buffer de la même taille
	file.seekg(0, std::ios::beg);


	file.read(&buffer[0], size); // comme un read() et on balance tout dans le buffer

	size_t pos = 0;
	while (true)
	{
		pos = buffer.find(strsource, pos);

		if (pos == std::string::npos)
			break; // didn't find shit
		buffer.replace(pos, strsource.length(), strdest);
		pos += strdest.length(); // support for string to be replaced inside the string to replace with

	}

	file2 << buffer;
	file.close();
	file2.close();
}

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: usage: ./replace <Filename> <string1> <string2>" << std::endl;
		return (0);
	}
	else if (argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		std::cout << "Error: One of the strings is empty" << std::endl;
		return (0);
	}
	else
		replace(argv);
	return (0);
}
