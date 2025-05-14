/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:50:48 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/14 01:48:37 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_name = "unknown";
	_hitPoints = 100; 
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {
	_name = name;
	_hitPoints = 100; 
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
	// _name = other._name; 
	// _hitPoints = other._hitPoints;
	// _energyPoints = other._energyPoints; 
	// _attackDamage = other._attackDamage;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	if (this != &other){
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap copy operator constructor called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor was called" << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	if (_hitPoints > 0 && _energyPoints > 0){
		_energyPoints -= 1;
		std::cout 
			<< "ScavTrap " << _name 
			<< " attacks " << target 
			<< ", causing " << _attackDamage 
			<< "points of damage!" << std::endl;
	}
	else
		std::cout 
			<< "ScavTrap " << _name 
			<< " can't attack" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!\n";
}