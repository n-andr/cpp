/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:27:59 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/17 22:14:12 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog() : Animal(){
	_type = "Dog";
	// std::cout << "Dog: default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other){
	this->_type = other._type;
	// std::cout << "Dog: copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other){	
	if(this != &other)
		this->_type = other._type;
	// std::cout << "Dog: Assigment operatour called" << std::endl;
	return *this;
}

Dog::~Dog(){
	// std::cout << "Dog: destructor called" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Dog: \"WUF! WUF!\"" << std::endl;
}