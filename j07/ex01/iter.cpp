
#include <iostream>
#include <unistd.h>





template<typename T>
void	iter( T* array, int length, void (*f)(T) )
{
	size_t len = 0;
	if (length < 0)
		return;
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





class Awesome {

public:
Awesome( void ) : _n( 42 ) { return; }
int get( void ) const { return this->_n; }

private:
int _n;};


std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }




int main(void)
{

	char dada[] = "LIBEREW LE TIBAY";

	iter(dada, 17, ft_putchar);


int tab[] = { 0, 1, 2, 3, 4 }; // <--- J'ai jamais compris pourquoi on peut pas ecrire int[] tab. Ca aurait plus de sens vous trouvez pas ?
Awesome tab2[5];

iter( tab, 5, print );
iter( tab2, 5, print );


}


