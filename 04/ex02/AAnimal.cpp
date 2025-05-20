/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:44:17 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/19 01:48:10 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Unknown AAnimal")
{
	std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) 
{
	std::cout << "AAnimal: Copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other){
	if (this != &other){
		_type = other._type;
	}
	std::cout << "AAnimal: Copy operator constructor called" << std::endl;
	return (*this);
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal: Destructor was called" << std::endl;
}

std::string AAnimal::getType() const{
	return (_type);
}

// void AAnimal::makeSound() const{
// 	std::cout << "AAnimal makes a sound" << std::endl;
// }

