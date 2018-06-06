#include <iostream>




template<typename T>
void swap (T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}



template<typename T>
T *min (T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}



template<typename T>
T *max (T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}




int main()
{
	int a = 1;
	int b = 2;
	std::cout << a << " " << b << std::endl;
	swap(a,b);
	std::cout << a << " " << b << std::endl;

	{
		float a = 1;
		float b = 2;
		std::cout << a << " " << b << std::endl;
		swap(a,b);
		std::cout << a << " " << b << std::endl;
	}

}