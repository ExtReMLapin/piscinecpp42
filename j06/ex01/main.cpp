#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

struct bitmap
{
	char 	_1[8];
	int 	_2;
	char 	_3[8];
};


struct 				Data
{
	std::string		s1;
	int				n;
	std::string		s2;
};

void shuffle(char *str)
{
	std::string  alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	size_t i = 0;
	while (i < 8)
	{
		while (!isalnum(str[i]))
			str[i] = static_cast<char>(alpha[rand()%(alpha.length())]);
		i++;
	}

}


void * serialize( void )
{
	bitmap	*	bits = new bitmap;

	shuffle(bits->_1);
	bits->_2 = rand();
	shuffle(bits->_3);
	return reinterpret_cast<void *>(bits);
}
Data * deserialize( void * raw )
{
	bitmap *	dat;
	Data *		data = new Data;

	dat = reinterpret_cast<bitmap *>(raw);
	data->s1 = static_cast<std::string>(dat->_1);
	data->n = dat->_2;
	data->s2 = static_cast<std::string>(dat->_3);
	return (data);
}


int 	main(void)
{
	void *		tmp;
	Data * 		ptr;

	std::srand(std::time(0));
	tmp = serialize();

	ptr = deserialize(tmp);


	std::cout << ptr->s1 << std::endl;
	std::cout << ptr->n << std::endl;
	std::cout << ptr->s2 << std::endl;
	return 0;
}