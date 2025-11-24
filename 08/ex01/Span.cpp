#include "Span.hpp"

Span::Span() : _size(0) { _data.reserve(0);}

Span::Span(unsigned int N) : _size(N) {
	 _data.reserve(N);
}

Span::Span(const Span& other) : _size(other._size), _data(other._data) {}

Span&	Span::operator=(const Span& other)
{
	if (this != &other) {
		_size = other._size;
		_data = other._data;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int number){
	if (_data.size() >= _size) 
		throw std::length_error("Span capacity is reached");
	_data.push_back(number);
}

// INT_MAX - INT_MIN = 4,294,967,295  → overflow!
//using long

unsigned long Span::longestSpan(){
	if (_data.size() < 2) 
		throw std::length_error("Span is too small");
	int min = *std::min_element(_data.begin(), _data.end());
	int max = *std::max_element(_data.begin(), _data.end());
	unsigned long longest = (unsigned long)max - (unsigned long)min;
	return longest;
}

unsigned long Span::shortestSpan(){
	if (_data.size() < 2) 
		throw std::length_error("Span is too small");
	std::vector<int> tmp = _data;
	std::sort(tmp.begin(), tmp.end());
	unsigned long shortest = (unsigned long)(tmp[1] - tmp[0]);
	for (unsigned int i = 1; i < tmp.size() - 1; i++){
		unsigned long diff = (unsigned long)(tmp[i + 1] - tmp[i]);
		if (diff < shortest)
            shortest = diff;
    }

    return shortest;
}