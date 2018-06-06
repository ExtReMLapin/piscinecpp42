
#include <iostream>
#include <unistd.h>





template< typename T , typename U>
void	iter(T *array, int lenght, void (*func) (U )) {

	for (int i = 0; i < lenght; i++) {
		func(array[i]);
	}
	return ;
}



static void ft_putchar(char c)
{
	write(1, &c, 1);
}





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




int main(void)
{

	char dada[] = "LIBEREW LE TIBAY";
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- J'ai jamais compris pourquoi on peut pas ecrire int[] tab. Ca aurait plus de sens vous trouvez pas ?
	Awesome tab2[5];
	iter( dada, 17, ft_putchar);
	iter( tab, 5, ft_putchar );
	iter( tab2, 5, ft_putchar );


}


