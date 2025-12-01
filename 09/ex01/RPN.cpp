#include "RNP.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other){}

RPN& RPN::operator=(const RPN& other) {
	return *this;
}

double RPN::calculate(const std::string& input){
	std::stack<double> numbers;
	if (input.empty())
		throw std::runtime_error("Empty input");
	if (input.find_first_not_of(" 0123456789+-/*") == std::string::npos)
		throw std::runtime_error("Invalid input");
	for (size_t i = 0; i < input.length(); i++){
		char c = input[i];
		if (std::isspace(c)) continue;
		else if (std::isdigit(c)) {numbers.push(std::strtod(c, NULL));}
		else
		{
			double first_digit = numbers.top(); 
			numbers.pop();
			double second_digit = numbers.top(); 
			numbers.pop();
			double result;
			switch (op)
			{
			case '+':
				result = first_digit + second_digit;
			case '-':
				result = first_digit - second_digit;
			case '*':
				result = first_digit * second_digit;
			case '/':
				if(second_digit == 0)
					throw std::runtime_error("Division by 0");
				result = first_digit / second_digit;
			default:
				throw std::runtime_error("Invalid input");
			}
			numbers.push(result);
		}
	}
}