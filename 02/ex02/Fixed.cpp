/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:20:59 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/13 00:24:18 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixPointNumber(0){
	//std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other){
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed& other){
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		setRawBits(other.getRawBits());
	return *this;
}

// shift integer to n bits left
// shifting 8 bits = multiply by 256 (2^8)
Fixed::Fixed(const int value) : fixPointNumber(value << bits){
	//std::cout << "Int constructor called" << std::endl;
	//std::cout << "Int:" << value << "fixPointNumber:" << fixPointNumber  << std::endl;
}

// round it to int and multipy by 256
Fixed::Fixed(const float value) : fixPointNumber(static_cast<int>(roundf(value * (1 << bits)))){
	//std::cout << "Float constructor called" << std::endl;
	//std::cout << "Float:" << value << "fixPointNumber:" << fixPointNumber  << std::endl;
}

Fixed::~Fixed(){
	//std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return fixPointNumber;
}

void Fixed::setRawBits( int const raw ){
	//std::cout << "setRawBits member function called" << std::endl;
	fixPointNumber = raw;
}

float Fixed::toFloat(void) const{
	return static_cast<float>(fixPointNumber) / (1 << bits);
}

int	Fixed::toInt(void) const{
	return fixPointNumber >> bits;
}

bool	Fixed::operator>(const Fixed &other) const{
	return fixPointNumber > other.fixPointNumber;
}

bool	Fixed::operator<(const Fixed &other) const{
	return fixPointNumber < other.fixPointNumber;
}

bool	Fixed::operator>=(const Fixed &other) const{
	return fixPointNumber >= other.fixPointNumber;
}

bool	Fixed::operator<=(const Fixed &other) const{
	return fixPointNumber <= other.fixPointNumber;
}

bool	Fixed::operator==(const Fixed &other) const{
	return fixPointNumber == other.fixPointNumber;
}

bool	Fixed::operator!=(const Fixed &other) const{
	return fixPointNumber != other.fixPointNumber;
}

Fixed	Fixed::operator+(const Fixed &other) const{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed 	Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed 	Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed 	Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& 	Fixed::operator++() {
	++fixPointNumber;
	return *this;
}

Fixed 	Fixed::operator++(int) {
	Fixed temp = *this;
	++fixPointNumber;
	return temp;
}

Fixed& 	Fixed::operator--() {
	--fixPointNumber;
	return *this;
}

Fixed 	Fixed::operator--(int) {
	Fixed temp = *this;
	--fixPointNumber;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

// The purpose of overloading the << operator is to make this class work naturally with std::cout, like built-in types.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}