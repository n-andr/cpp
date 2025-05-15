/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:42:49 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/15 01:59:37 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
	: ClapTrap("unknown_clap_name"),
	ScavTrap("unknown_clap_name"),
	FragTrap("unknown_clap_name"),
	_name("unknown")
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::defaultEnergy;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " default constructor called" << std::endl;
	std::cout << "DiamondTrap _hitPoints: " << _hitPoints << std::endl;
	std::cout << "DiamondTrap _energyPoints: " << _energyPoints << std::endl;
	std::cout << "DiamondTrap _attackDamage: " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) 
	: ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"),
	_name(name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::defaultEnergy;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " default constructor called" << std::endl;
	std::cout << "DiamondTrap _hitPoints: " << _hitPoints << std::endl;
	std::cout << "DiamondTrap _energyPoints: " << _energyPoints << std::endl;
	std::cout << "DiamondTrap _attackDamage: " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
	: ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	_name(other._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}	

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		ClapTrap::operator=(other);
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}