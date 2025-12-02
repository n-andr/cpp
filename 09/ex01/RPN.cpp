#include "RNP.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other){ (void)other;}

RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

double RPN::calculate(const std::string& input){
	std::stack<double> numbers;
	if (input.empty())
		throw std::runtime_error("Error: empty input");
	if (input.find_first_not_of(" 0123456789+-/*") != std::string::npos)
		throw std::runtime_error("Error: invalid character in input");
	for (size_t i = 0; i < input.length(); i++){
		char c = input[i];
		if (std::isspace(c)) continue;
		else if (std::isdigit(c))
		{
			numbers.push(static_cast<double>(c - '0'));
		}
		else
		{
			if (numbers.size() < 2)
                throw std::runtime_error("Error: not enough operands");
			double second_digit = numbers.top(); 
			numbers.pop();
			double first_digit = numbers.top(); 
			numbers.pop();
			double result;
			switch (c)
			{
			case '+':
				result = first_digit + second_digit;
				break;
			case '-':
				result = first_digit - second_digit;
				break;
			case '*':
				result = first_digit * second_digit;
				break;
			case '/':
				if(second_digit == 0)
					throw std::runtime_error("Error: Division by 0");
				result = first_digit / second_digit;
				break;
			default:
				throw std::runtime_error("Error: Invalid input");
			}
			numbers.push(result);
		}
	}
	if (numbers.size() != 1)
        throw std::runtime_error("Error: too many operands");
	return numbers.top();
}