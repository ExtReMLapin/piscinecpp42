
#include <iostream>
#include <unistd.h>


template<typename T, typename U>
void	iter( T* array, size_t length, void (*f)(U) )
{
	size_t len = 0;
	while (len < length)
	{
		f(array[len]);
		len++;
	}

}


static void ft_putchar(char c)
{
	write(1, &c, 1);
}


int main(void)
{

	char dada[] = "LIBEREW LE TIBAY";

	iter(dada, static_cast<size_t>(17), ft_putchar);

}