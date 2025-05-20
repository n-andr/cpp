/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:27:59 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/20 01:07:51 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog() : Animal(){
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog: default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other){
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog: copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other){	
	if(this != &other){
		this->_type = other._type;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << "Dog: Assigment operatour called" << std::endl;
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog: destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const{
	std::cout << "Dog: \"WUF! WUF!\"" << std::endl;
}

Brain* Dog::getBrain() const{
	return (_brain);
}