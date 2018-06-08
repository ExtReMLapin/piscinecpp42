#pragma once
#include <stack>

template< typename T >
class MutantStack : public std::stack<T> {

	public:
		MutantStack() {
		}

		~MutantStack() {
		}

		MutantStack(MutantStack const& src) : std::stack<T>(src) {
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		
		iterator begin() {
			return std::stack<T>::c.begin();
		}

		iterator end()	{
			return std::stack<T>::c.end();
		}

		using std::stack<T>::operator=;
	protected:
	private:
};
