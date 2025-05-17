/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:27:59 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/17 22:58:58 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	_type = "WrongCat";
	// std::cout << "WrongCat: default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
	this->_type = other._type;
	// std::cout << "WrongCat: copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){	
	if(this != &other)
		this->_type = other._type;
	// std::cout << "WrongCat: Assigment operatour called" << std::endl;
	return *this;
}

WrongCat::~WrongCat(){
	// std::cout << "WrongCat: destructor called" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "WrongCat: \"MEUW! MEOW!\"" << std::endl;
}