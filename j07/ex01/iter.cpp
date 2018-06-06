
#include <iostream>
#include <unistd.h>


class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }


template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }



template< typename T>
void	iter(T const *array, int lenght, void (*func) (T const & x ))
{
	int i = 0;
	while (i < lenght)
	{
		func(array[i]);
		i++;
	}
	return ;
}



int main(void)
{

	char dada[] = "LIBEREW LE TIBAY";
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- J'ai jamais compris pourquoi on peut pas ecrire int[] tab. Ca aurait plus de sens vous trouvez pas ?
	Awesome tab2[5];
	iter( dada, 16, print);
	iter( tab, 5, print );
	iter( tab2, 5, print );
}
