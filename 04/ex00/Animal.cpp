/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:44:17 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/17 22:17:39 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown animal")
{
	//::cout << "Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) 
{
	//::cout << "Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
	if (this != &other){
		_type = other._type;
	}
	//::cout << "Copy operator constructor called" << std::endl;
	return (*this);
}

Animal::~Animal(){
	//std::cout << "Destructor was called" << std::endl;
}

std::string Animal::getType() const{
	return (_type);
}

void Animal::makeSound() const{
	std::cout << "Animal makes a sound" << std::endl;
}

