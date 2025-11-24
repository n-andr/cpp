#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>
# include <stdexcept>  
//# include <cstdlib> // abs()

class Span{
	private:
		unsigned int _size;
		std::vector<int> _data;

	public:

		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		void addNumber(int number);
		unsigned long shortestSpan();
		unsigned long longestSpan();

		template <typename It>
		void addRange(It begin, It end){
			if ( ( _data.size() + std::distance(begin, end) ) > _size ) 
				throw std::length_error("Range is too big");
			_data.insert(_data.end(), begin, end);
		}
};



#endif