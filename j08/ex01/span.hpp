#pragma once

#include <vector>

class Span {
	public:
		Span(unsigned int size);
		Span(int size);
		~Span();
		void addNumber(int i);
		int	shortestSpan();
		int longestSpan();
		Span & operator=(const Span & rhs);
		Span();
		Span(Span const &source);
		void fillRandom();
	private:


		std::vector<int> _db;
		
};