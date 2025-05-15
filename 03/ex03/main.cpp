/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:19:03 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/15 01:17:29 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){
	std::cout << "==Original ClapTrap ==" << std::endl << std::endl;
	ClapTrap unknown;

	ClapTrap karl("Karl");

    karl.attack("Dummy");
	unknown.attack("Dummy");

	std::cout << std::endl << "==DimondTrap no name==" << std::endl << std::endl;
	DiamondTrap diamond;
	std::cout << std::endl;
	diamond.whoAmI();
	// diamond.highFivesGuys();

	std::cout << std::endl <<  "==DimondTrap with name==" << std::endl << std::endl;
	DiamondTrap diamond2("Diamond");
	std::cout << std::endl;
	diamond2.attack("Dummy");
	diamond2.whoAmI();
	//diamond2.highFivesGuys();
	
	std::cout << std::endl << "==Destructors ==" << std::endl << std::endl;

	return 0;
}