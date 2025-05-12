/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:20:56 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/13 00:22:28 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Orthodox Canonical Class Form
must have atleast:
	Default constructor
	Copy constructor
	Copy assignment operator
	Destructor
	

	class Sample {
		private:
			int value;
		public:
			Sample();                            // Default constructor
			Sample(const Sample& other);         // Copy constructor - create an new object
			Sample& operator=(const Sample& other); // Copy assignment operator - assign obj properties to existing obj
			~Sample();                           // Destructor
};

*/

/*

A fixed-point is just an integer here you pretend some bits are after
a decimal point.
The last 8 bits are the fractional part, and the rest is the integer part
(int got 32 bits, so 32 - 8 = 24 bits for the integer part).

*/

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class  Fixed
{
private:
	int fixPointNumber;
	static const int bits = 8;
public:
	// costructours
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	Fixed(const int value);
	Fixed(const float value);

	// destructor
	~Fixed();

	// getter and setter
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	
	// convertion fuctions
	float	toFloat( void ) const;
	int		toInt( void ) const;

	// comparison operators: >, <, >=, <=, ==, and !=
	bool 	operator>(const Fixed &other) const;
	bool 	operator<(const Fixed &other) const;
	bool 	operator>=(const Fixed &other) const;
	bool 	operator<=(const Fixed &other) const;
	bool 	operator==(const Fixed &other) const;
	bool 	operator!=(const Fixed &other) const;

	// arithmetic operators: +, -, *, and /
	Fixed 	operator+(const Fixed &other) const;
	Fixed 	operator-(const Fixed &other) const;
	Fixed 	operator*(const Fixed &other) const;
	Fixed 	operator/(const Fixed &other) const;
	
	// increment/decrement
	Fixed&	operator++();		//pre 
	Fixed	operator++(int);	//post int is dummy syntax to distinguish it from pre-increment
	Fixed&	operator--();		//pre
	Fixed	operator--(int);	//post

	// min/max
	static Fixed& min(Fixed& a, Fixed& b); // Returns non-const reference to the smaller value
	static const Fixed& min(const Fixed& a, const Fixed& b); // Returns const reference to the smaller value
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif