/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:44:17 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/19 01:48:10 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) 
{
	std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
	if (this != &other){
		_type = other._type;
	}
	std::cout << "Animal: Copy operator constructor called" << std::endl;
	return (*this);
}

Animal::~Animal(){
	std::cout << "Animal: Destructor was called" << std::endl;
}

std::string Animal::getType() const{
	return (_type);
}

void Animal::makeSound() const{
	std::cout << "Animal makes a sound" << std::endl;
}

