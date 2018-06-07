#include <stdexcept>

template< typename T = int>
class Array
{
	public:
		Array<T>(): _array( NULL ), _size( 0 ) {}; // Construction with no parameter: creates an empty array
		Array<T>( unsigned int n ): _size( n )
		{

			if ( _size == 0 )
				_array = NULL;
			else
				_array = new T[n]; // Construction with an unsigned int n as a parameter: creates an array of n elements,initialized by default.
		};

		Array<T>( Array<T> const & src ): _array( NULL ), _size( 0 )
		{
			*this = src;
		};

		~Array<T>() {};

		unsigned int	size() const {
			return ( this->_size );
		};

		Array<T> &	operator=( Array<T> const & rhs ) {
			if ( this != &rhs ) {
				if (this->_array != NULL) // Your code must never access non allocated memory
					delete [] this->_array;
				this->_size = rhs._size;
				if (this->_size == 0) // Your code must never access non allocated memory
					this->_array = NULL;
				else
					this->_array = new T[rhs._size];
				unsigned int i = 0;
				while (i < rhs._size)
				{
					this->_array[i] = rhs._array[i];
					i++;
				}		
			}
			return *this;
		};

		T &	operator[]( unsigned int num ) {
			if ( num < this->_size )
				return ( this->_array[num] );
			else
				throw std::range_error("You don't have access to this adr");
		};

	private:
		T*				_array;
		unsigned int	_size;
};
