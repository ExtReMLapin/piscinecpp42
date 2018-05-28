#include "Contact.hpp"

Contact::Contact()
{
	this->isInit = false;
	return ;
}

Contact::~Contact()
{
	return ;
}

bool	Contact::isInitialized(void)
{
	return (this->isInit);
}

static bool checkascii(std::string str)
{
	size_t i = 0;
	while ( i < str.length())
	{
		if (!std::isprint(str[i]))
		{
			std::cout << "WRONG CHAR, FUCK OFF" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

void		Contact::addNew(void)
{
	
	std::cout << "Enter firstname: ";
	std::getline (std::cin, this->first_name);
	if (checkascii(this->first_name) == false)
		return; 

	std::cout << "Enter lastname: ";
	std::getline (std::cin, this->last_name);
	if (checkascii(this->last_name) == false)
		return; 

	std::cout << "Enter nickname: ";
	std::getline (std::cin, this->nickname);
	if (checkascii(this->nickname) == false)
		return; 

	std::cout << "Enter login: ";
	std::getline (std::cin, this->login);
	if (checkascii(this->login) == false)
		return; 

	std::cout << "Enter postal address: ";
	std::getline (std::cin, this->postal_address);
	if (checkascii(this->postal_address) == false)
		return; 

	std::cout << "Enter email: ";
	std::getline (std::cin, this->email_address);
	if (checkascii(this->email_address) == false)
		return; 

	std::cout << "Enter phone number: ";
	std::getline (std::cin, this->phone_number);
	if (checkascii(this->phone_number) == false)
		return; 

	std::cout << "Enter birthday: ";
	std::getline (std::cin, birthday_date);
	if (checkascii(this->birthday_date) == false)
		return; 

	std::cout << "Enter favorite meal: ";
	std::getline (std::cin, this->favorite_meal);
	if (checkascii(this->favorite_meal) == false)
		return; 

	std::cout << "Enter underwear color: ";
	std::getline (std::cin, this->underwear_color);
	if (checkascii(this->underwear_color) == false)
		return; 

	std::cout << "Enter darkest secret: ";
	std::getline (std::cin, this->darkest_secret);
	if (checkascii(this->darkest_secret) == false)
		return; 

	this->isInit = true;
}

 
std::string Contact::getField(uint8_t fieldID, bool truncated) const
{
	std::string out;

	switch (fieldID)
	{
		case 1 :
					out = this->first_name;
					break;
		case 2 : 
					out = this->last_name;
					break;
		case 3 : 
					out = this->nickname;
					break;
		case 4 : 
					out = this->login;
					break;
		case 5 : 
					out = this->postal_address;
					break;
		case 6 : 
					out = this->email_address;
					break;
		case 7 : 
					out = this->phone_number;
					break;
		case 8 : 
					out = this->birthday_date;
					break;
		case 9 : 
					out = this->favorite_meal;
					break;
		case 10 : 
					out = this->underwear_color;
					break;
		case 11 : 
					out = this->darkest_secret;
					break;

		default: out = this->first_name;
	}

	if (truncated && out.length() > 10)
	{
		out.resize(9);
		out.resize(10, '.');
	}

	return (out);
}