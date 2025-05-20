/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal copy.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:44:17 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/17 22:31:37 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown WrongAnimal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) 
{
	//::cout << "Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	if (this != &other){
		_type = other._type;
	}
	std::cout << "Animal: Copy operator constructor called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Animal: Destructor was called" << std::endl;
}

std::string WrongAnimal::getType() const{
	return (_type);
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal makes a wrong sound" << std::endl;
}

