/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:40:40 by nandreev          #+#    #+#             */
/*   Updated: 2025/11/03 00:04:50 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScalarConverter.hpp"
// #include "include/helpers.hpp"


#include <iomanip>   // for std::fixed and std::setprecision
#include <cstdlib>   // for std::strtol, std::strtod, std::strtof
// #include <cmath>    // for finite()
// #include <math.h>
#include <climits>   // for INT_MAX, INT_MIN
// #include <cfloat>    // for FLT_MAX
// #include <cmath>     // for isnan, isinf
// #include <cerrno>    // for errno
# include <sstream>	// for std::ostringstream


ScalarConverter::ScalarConverter(){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {return *this;}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}
ScalarConverter::~ScalarConverter(){}


static bool isPseudoLiteral(std::string input){
	return (input == "nan" || input == "nanf"
		|| input == "+nan" || input == "+nanf"
		|| input == "-nan" || input == "-nanf"
		|| input == "inf" || input == "inff"
		|| input == "+inf" || input == "+inff"
		|| input == "-inf" || input == "-inff");
}

static int getPrecision(std::string s){
	std::size_t dotPosition = s.find('.');
	if (dotPosition == std::string::npos) return 1;
	return static_cast<int>(s.length() - dotPosition - 1 - (s[s.length() - 1] == 'f' ? 1 : 0));
	
}

// helper: format numbers depending on magnitude
static std::string format_float(float v, int fixed_prec) {
    std::ostringstream os;
    float a = v < 0 ? -v : v;
    if ((a >= 1e6f) || (a > 0.0f && a < 1e-4f)) {
        os.setf(std::ios::scientific, std::ios::floatfield);
        os << std::setprecision(1) << v << 'f';  // "9e+11f" style
    } else {
        os.setf(std::ios::fixed, std::ios::floatfield);
        os << std::setprecision(fixed_prec) << v << 'f'; // "900.0f" style
    }
    return os.str();
}

static std::string format_double(double v, int fixed_prec) {
    std::ostringstream os;
    double a = v < 0 ? -v : v;
    if ((a >= 1e6) || (a > 0.0 && a < 1e-4)) {
        os.setf(std::ios::scientific, std::ios::floatfield);
        os << std::setprecision(1) << v;         // "9e+11"
    } else {
        os.setf(std::ios::fixed, std::ios::floatfield);
        os << std::setprecision(fixed_prec) << v; // "900.0"
    }
    return os.str();
}

static bool is_nan(double x) { return x != x; }

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

	
	// long l = std::strtol(input.c_str(), &endptr, 10); // sets errno to ERANGE if overflow/underflow of long
	// if (*endptr == '\0' && errno != ERANGE)
	// {
	// 	float f = static_cast<float>(l);
    //     double d = static_cast<double>(l);
		
	// 	if(l < INT_MIN || l > INT_MAX){
	// 		std::cout << "char: impossible" << std::endl;
    //     	std::cout << "int: impossible" << std::endl;
	// 	} else {
	// 		int i = static_cast<int>(l);
	// 		if (i >= 32 && i <= 126)
	// 			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	// 		else if (i >= 0 && i <= 127)
	// 			std::cout << "char: Non displayable" << std::endl;
	// 		else
	// 			std::cout << "char: impossible" << std::endl;
	// 		std::cout << "int: " << i << std::endl;
	// 	}
	// 	std::cout << std::fixed << std::setprecision(prec) << "float: " << f << "f" ;
	// 	if (static_cast<double>(f) != d)
    //     	std::cout << " (warning: precision loss)"; // can happen if int length is more than 7 digits
    // 	std::cout << std::endl;
    //     std::cout << std::fixed << std::setprecision(prec) << "double: " << d << std::endl;
	// 	return;
	// }



	
	//float
	errno = 0;
	// float f = std::strtof(input.c_str(), &endptr);
	if (!input.empty() && input[input.size()-1] == 'f') {
   		// parse the numeric part with strtod (more portable than strtof)
		std::string core = input.substr(0, input.size()-1);
		double d = std::strtod(core.c_str(), &endptr);

		if (*endptr == '\0') {
			// overflow/underflow to +/-inf for float?
			if (is_nan(d)) {
				std::cout << "char: impossible\nint: impossible\n";
				std::cout << "float: nanf\n";
				std::cout << "double: nan" << std::endl;
				return;
			}

			if (d > std::numeric_limits<float>::max()) {
				std::cout << "char: impossible\nint: impossible\n";
				std::cout << "float: inff\n";
				// double might still be finite or may have overflowed itself:
				if (d == std::numeric_limits<double>::infinity())
					std::cout << "double: inf" << std::endl;
				else
					std::cout << "double: " << format_double(d, prec) << std::endl;
				return;
			}
			if (d < -std::numeric_limits<float>::max()) {
				std::cout << "char: impossible\nint: impossible\n";
				std::cout << "float: -inff\n";
				if (d == -std::numeric_limits<double>::infinity())
					std::cout << "double: -inf" << std::endl;
				else
					std::cout << "double: " << format_double(d, prec) << std::endl;
				return;
			}

			// finite float path
			float f = static_cast<float>(d);
			char c = static_cast<char>(f);
			int  i = static_cast<int>(f);

			if (f >= 32.0f && f <= 126.0f)       std::cout << "char: '" << c << "'\n";
			else if (f >= 0.0f && f < 128.0f)    std::cout << "char: Non displayable\n";
			else                                 std::cout << "char: impossible\n";

			if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX))
				std::cout << "int: " << i << "\n";
			else
				std::cout << "int: impossible\n";

			std::cout << "float: "  << format_float(f, prec)  << "\n";
			std::cout << "double: " << format_double(d, prec) << std::endl;
			return;
		}
	}
	//double
	errno = 0;
	endptr = 0;
	double d = std::strtod(input.c_str(), &endptr);
	if (*endptr == '\0') {
        // NaN?
        if (is_nan(d)) {
            std::cout << "char: impossible\nint: impossible\n";
            std::cout << "float: nanf\n";
            std::cout << "double: nan" << std::endl;
            return;
        }

        // +/-inf?  (C++98-safe check via numeric_limits)
        const double posNif =  std::numeric_limits<double>::infinity();
        const double negInf = -std::numeric_limits<double>::infinity();
        if (d == posNif || d == negInf || errno == ERANGE) {
            std::cout << "char: impossible\nint: impossible\n";
            std::cout << "float: "  << (d > 0 ? "inff" : "-inff") << "\n";
            std::cout << "double: " << (d > 0 ? "inf"  : "-inf")  << std::endl;
            return;
        }

        // finite path
        const char  c = static_cast<char>(d);
        const int   i = static_cast<int>(d);

        if (d >= 32.0 && d <= 126.0)          std::cout << "char: '" << c << "'\n";
        else if (d >= 0.0 && d < 128.0)       std::cout << "char: Non displayable\n";
        else                                  std::cout << "char: impossible\n";

        if (d >= static_cast<double>(INT_MIN) &&
            d <= static_cast<double>(INT_MAX)) std::cout << "int: " << i << "\n";
        else                                   std::cout << "int: impossible\n";

        // float line: show inff if it doesn't fit in float
        if (d >  std::numeric_limits<float>::max()) {
            std::cout << "float: inff\n";
        } else if (d < -std::numeric_limits<float>::max()) {
            std::cout << "float: -inff\n";
        } else {
            const float f = static_cast<float>(d);
            std::cout << "float: " << format_float(f, prec) << "\n";
        }

        // double line with smart formatting
        std::cout << "double: " << format_double(d, prec) << std::endl;
        return;
	} else
		std::cout << "fuck" << std::endl;
	

	std::cout << "Literal could not be converted" << std::endl;

		
}