/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:44:17 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/13 02:40:10 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
	: _name("unknown"), 
	_hitPoints(10), 
	_energyPoints(10), 
	_attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), 
	_hitPoints(10), 
	_energyPoints(10), 
	_attackDamage(0)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), 
	_hitPoints(other._hitPoints), 
	_energyPoints(other._energyPoints), 
	_attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if (this != &other){
		_name = other._name;
		_hitPoints = other._hitPoints;
		_attackDamage = other._attackDamage;
		_energyPoints = other._energyPoints;
	}
	std::cout << "Copy operator constructor called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor was called" << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	if (_hitPoints > 0 && _energyPoints > 0){
		_energyPoints -= 1;
		std::cout 
			<< "ClapTrap " << _name 
			<< " attacks " << target 
			<< ", causing " << _attackDamage 
			<< "points of damage!" << std::endl;
	}
	else
		std::cout 
			<< "ClapTrap " << _name 
			<< " can't attack" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int ammount){
	if (ammount < _hitPoints){
		_hitPoints -= ammount;
	} else {
		_hitPoints = 0;
	}
	std::cout 
			<< "ClapTrap " << _name 
			<< " was attacked and has " << _hitPoints 
			<< "/10 hit points left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int ammount){
	if (_energyPoints > 0 && _hitPoints > 0){
		_energyPoints -= 1;
		_hitPoints += ammount;
		if (_hitPoints > 10) 
			_hitPoints = 10;
		std::cout 
			<< "ClapTrap " << _name 
			<< " repairs itself by adding "
			<< ammount << " points! And now has"
			<< _hitPoints <<"/10 hit points" << std::endl;
	}
	else
		std::cout 
			<< "ClapTrap " << _name 
			<< " can't repair" << std::endl;
	
}