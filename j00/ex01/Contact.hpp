#pragma once

#include <string>
#include <iostream>

class Contact
{
public:
	Contact();
	~Contact();

	std::string getField(uint8_t fieldID, bool truncated);
	void		addNew(void);
	bool		isInitialized();

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;
	bool isInit;

};