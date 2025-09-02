/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:40:40 by nandreev          #+#    #+#             */
/*   Updated: 2025/09/02 17:05:32 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iomanip>   // for std::fixed and std::setprecision
#include <cstdlib>   // for std::strtol, std::strtod, std::strtof
#include <climits>   // for INT_MAX, INT_MIN
//#include <cfloat>    // for FLT_MAX
#include <cmath>     // for isnan, isinf std::fabs
#include <cerrno>    // for errno

ScalarConverter::ScalarConverter(){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {return *this;}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}
ScalarConverter::~ScalarConverter(){}


static bool isPseudoLiteral(std::string input){
	return (input == "nan" || input == "nanf"
		|| input == "+inf" || input == "+inff"
		|| input == "-inf" || input == "-inff");
}

static int getPrecision(std::string s){
	std::size_t dotPosition = s.find('.');
	if (dotPosition == std::string::npos) return 1;
	return static_cast<int>(s.length() - dotPosition - 1 - (s[s.length() - 1] == 'f' ? 1 : 0));
	
}

void ScalarConverter::convert(const std::string& input){
	if (input.empty()) {
		std::cout << "Error: empty input" << std::endl;
        return;
	}
	//pseudo literal
	if (isPseudoLiteral(input)){
		float f = std::strtof(input.c_str(), NULL);
		double d = static_cast<double>(f);
		
		std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
		return;
	}
	//char
	if (input.length() == 1 && !std::isdigit(input[0]) && input[0] >= 32 && input[0] <= 126) {
		char c = input[0];
		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);

		std::cout << "char: " << c << std::endl;
        std::cout << "int: " << i << std::endl;
         std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
		return;
	}
	
	char* endptr = NULL;
	errno = 0;
	int prec = getPrecision(input);
	//int
	long l = std::strtol(input.c_str(), &endptr, 10); // sets errno to ERANGE if overflow/underflow of long
	if (*endptr == '\0' && errno != ERANGE)
	{
		float f = static_cast<float>(l);
        double d = static_cast<double>(l);
		
		if(l < INT_MIN || l > INT_MAX){
			std::cout << "char: impossible" << std::endl;
        	std::cout << "int: impossible" << std::endl;
		} else {
			int i = static_cast<int>(l);
			if (i >= 32 && i <= 126)
				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
			else if (i >= 0 && i <= 127)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
			std::cout << "int: " << i << std::endl;
		}
		std::cout << std::fixed << std::setprecision(prec) << "float: " << f << "f" ;
		if (static_cast<double>(f) != d)
        	std::cout << " (warning: precision loss)"; // can happen if int length is more than 7 digits
    	std::cout << std::endl;
        std::cout << std::fixed << std::setprecision(prec) << "double: " << d << std::endl;
		return;
	}
	//float
	errno = 0;
	float f = std::strtof(input.c_str(), &endptr);
	if (*endptr == 'f' && *(endptr + 1) == '\0' && errno != ERANGE)
	{
		char c = static_cast<char>(f);
		int i = static_cast<int>(f);
		double d = static_cast<double>(f);
		if (f >= 32.0f && f <= 126.0f)
			std::cout << "char: '" << c << "'" << std::endl;
		else if (f >= 0.0f && f < 128.0f)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

		if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX))
            std::cout << "int: " << i << std::endl;
        else
			std::cout << "int: impossible" << std::endl;

		std::cout << std::fixed << std::setprecision(prec) << "float: " << f << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(prec) << "double: " << d << std::endl;
		return;
	}

	//double
	errno = 0;
	double d = std::strtod(input.c_str(), &endptr);
	if (*endptr == '\0' && errno != ERANGE)
	{
		char c = static_cast<char>(d);
		int i = static_cast<int>(d);
		f = static_cast<double>(d);
		if (d >= 32.0 && d < 127.0)
			std::cout << "char: '" << c << "'" << std::endl;
		else if (d >= 0.0 && d < 128.0)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

		if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX))
            std::cout << "int: " << i << std::endl;
        else
			std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(prec) << "float: " << f << "f" ;
		if (std::fabs(f - std::strtof(input.c_str(), NULL)) > 1e-6)
        	std::cout << " (warning: precision loss)"; // can happen if double length is too big
    	std::cout << std::endl;
		std::cout << std::fixed << std::setprecision(prec) << "double: " << d << std::endl;
		return;
	}


	std::cout << "Literal could not be converted" << std::endl;

		
}