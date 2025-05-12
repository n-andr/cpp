/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:19:03 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/13 00:30:33 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	

	// Fixed c(10);          
	// Fixed d(42.42f);     

	// std::cout << std::boolalpha; // print true/false instead of 1/0

	// std::cout << "c > d: " << (c > d) << std::endl;   // false
	// std::cout << "c < d: " << (c < d) << std::endl;   // true
	// std::cout << "c >= d: " << (c >= d) << std::endl; // false
	// std::cout << "c <= d: " << (c <= d) << std::endl; // true
	// std::cout << "c == d: " << (c == d) << std::endl; // false
	// std::cout << "c != d: " << (c != d) << std::endl; // true

	// Fixed e(10);
	// std::cout << "c == e: " << (c == e) << std::endl; // true
	
	return 0;
}