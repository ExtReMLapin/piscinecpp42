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


	if (strdest.find(strsource) != std::string::npos)
	{
		std::cout << "strRemplaceBy contains strFindStrToReplace, in other words, don't try to replace a string by another string containing itself" << std::endl;
	}


	file.open(argv[1]);
	file2.open(newfile.c_str());

	if (!file.is_open() || !file2.is_open() ) // bein ui
	{
		std::cout << "Error: Unable to open one of the files." << std::endl;
		return;
	}

	file.seekg(0, std::ios::end); 
	size = file.tellg(); // comme ici : http://www.cplusplus.com/reference/istream/istream/tellg/
	std::string	buffer(size, ' ');
	file.seekg(0, std::ios::beg);
	file.read(&buffer[0], size);
	while (buffer.find(strsource) != (size_t)-1) // loop et remplace tant que on en trouve
		buffer.replace(buffer.find(strsource), strsource.length(), strdest);
	file2 << buffer;
	file.close();

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
