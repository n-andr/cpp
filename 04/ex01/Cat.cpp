/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:27:59 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/20 01:07:41 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(){
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat: default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other){
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat: copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other){	
	if(this != &other){
		this->_type = other._type;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << "Cat: Assigment operatour called" << std::endl;
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat: destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const{
	std::cout << "Cat: \"MEUW! MEOW!\"" << std::endl;
}

Brain* Cat::getBrain() const{
	return (_brain);
}