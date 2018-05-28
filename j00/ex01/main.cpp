#include "Contact.hpp"
#include <iomanip> 
#include <limits>

static bool startwith(std::string start, std::string with)
{
	if (start == with)
		return (true);
	if (with.length() > start.length())
		return (false);
	size_t i = 0;
	const size_t len = with.length();
	while (i < len)
	{
		if (std::toupper(start[i]) != std::toupper(with[i]))
			return (false);
		i++;
	}
	return (true);
}


static void handle_command(std::string command, std::string *commands, Contact *contacts)
{
	if (startwith(command, commands[0])) // add
	{
		int i = 0;
		while (contacts[i].isInitialized() && i < 8)
			i++;
		if (i == 8)
		{
			std::cout << "Sorry comrad, you can't add anyone else." << std::endl;
			return ;
		}
		contacts[i].addNew();
		return ;
	}
	else if (startwith(command, commands[1])) // search
	{
		std::cout << "┍━━━━━━━━━━┲━━━━━━━━━━┲━━━━━━━━━━┲━━━━━━━━━━┑" << std::endl;
		std::cout << "┃     Index┃First name┃ Last name┃  Nickname┃" << std::endl;

		int i = 0;
		int max = -1;
		while (contacts[i].isInitialized() && i < 8)
		{
			max = i;
			i++;
		}
		i = 0;
		while (contacts[i].isInitialized() && i < 8)
		{
			std::cout << "┣━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━┫" << std::endl;

			std::cout << "┃" ;

			std::cout << std::setfill (' ') << std::setw (10);
			std::cout << i << "┃";
			std::cout << std::setfill (' ') << std::setw (10);
			std::cout << contacts[i].getField(1, true) << "┃";
			std::cout << std::setfill (' ') << std::setw (10);
			std::cout << contacts[i].getField(2, true) << "┃";
			std::cout << std::setfill (' ') << std::setw (10);
			std::cout << contacts[i].getField(3, true) << "┃" << std::endl;
			i++;
		}

		std::cout << "┕━━━━━━━━━━┺━━━━━━━━━━┺━━━━━━━━━━┺━━━━━━━━━━┙" << std::endl;

		if (max == -1)
			return;
		std::cout << "Enter the index of the guy you wanna get infos about [IT HAS TO BE A SINGLE DIGIT]: ";
		std::string number;
		int x = 0;
		while (true)
		{
			std::getline (std::cin,number);
			if (number.length() != 1)
				std::cout << "[TRUMP VOICE] : W R O N G ." << std::endl << "Enter the index of the guy you wanna get infos about [IT HAS TO BE A SINGLE DIGIT]: ";
			if (std::cin.eof() == 1)
				return ;
			if (number.length() == 1 && std::isdigit(number[0]))
			{
				x = (unsigned int)number[0] - 48;
				if (x > max)
					std::cout << "[TRUMP VOICE] : W R O N G ." << std::endl << "Enter the index of the guy you wanna get infos about [IT HAS TO BE A SINGLE DIGIT]: ";
				else
					break;
			}
		}
		 
		std::cout << "User firstname: " << contacts[x].getField(1, false) << std::endl;
		std::cout << "User lastname: " << contacts[x].getField(2, false) << std::endl;
		std::cout << "User nickname: " << contacts[x].getField(3, false) << std::endl;
		std::cout << "User login: " << contacts[x].getField(4, false) << std::endl;
		std::cout << "User postal address: " << contacts[x].getField(5, false) << std::endl;
		std::cout << "User email: " << contacts[x].getField(6, false) << std::endl;
		std::cout << "User phone number: " << contacts[x].getField(7, false) << std::endl;
		std::cout << "User birthday: " << contacts[x].getField(8, false) << std::endl;
		std::cout << "User favorite meal: " << contacts[x].getField(9, false) << std::endl;
		std::cout << "User underwear color: " << contacts[x].getField(10, false) << std::endl;
		std::cout << "User darkest secret: " << contacts[x].getField(11, false) << std::endl;

		return ;
	}
	else
		std::cout << "Unknown command. Available commands are :" << std::endl << "	ADD" << std::endl << "	SEARCH" << std::endl << "	EXIT" << std::endl;
}

int main(void)
{
	Contact contacts[8];
	std::string commands[3];
	std::string		line;

	commands[0] = "ADD";
	commands[1] = "SEARCH";
	commands[2] = "EXIT";

	while (std::cin.eof() != 1)
	{
		std::cout << "Enter a command: ";
		std::getline (std::cin, line);
		if (startwith(line, commands[2]))
			break;
		handle_command(line, commands, contacts);
	}
	return 0;

}