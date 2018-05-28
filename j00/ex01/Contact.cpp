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

void		Contact::addNew(void)
{
	this->isInit = true;
	std::cout << "Enter firstname: ";
	std::getline (std::cin, this->first_name);
	std::cout << "Enter lastname: ";
	std::getline (std::cin, this->last_name);
	std::cout << "Enter nickname: ";
	std::getline (std::cin, this->nickname);
	std::cout << "Enter login: ";
	std::getline (std::cin, this->login);
	std::cout << "Enter postal address: ";
	std::getline (std::cin, this->postal_address);
	std::cout << "Enter email: ";
	std::getline (std::cin, this->email_address);
	std::cout << "Enter phone number: ";
	std::getline (std::cin, this->phone_number);
	std::cout << "Enter birthday: ";
	std::getline (std::cin, birthday_date);
	std::cout << "Enter favorite meal: ";
	std::getline (std::cin, this->favorite_meal);
	std::cout << "Enter underwear color: ";
	std::getline (std::cin, this->underwear_color);
	std::cout << "Enter darkest secret: ";
	std::getline (std::cin, this->darkest_secret);
}

 
std::string Contact::getField(uint8_t fieldID, bool truncated)
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