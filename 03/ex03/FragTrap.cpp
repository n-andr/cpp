/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 02:39:31 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/14 02:49:54 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_name = "unknown";
	_hitPoints = 100; 
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
	_name = name;
	_hitPoints = 100; 
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	if (this != &other){
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap copy operator constructor called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor was called" << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap requests a high five" << std::endl;
}