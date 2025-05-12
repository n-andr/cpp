/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:20:59 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/12 01:09:56 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixPointNumber(0){
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)					// Avoid self-assignment
		setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixPointNumber;
}
void Fixed::setRawBits( int const raw ){
	//std::cout << "setRawBits member function called" << std::endl;
	fixPointNumber = raw;
}