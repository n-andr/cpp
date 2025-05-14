/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:19:03 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/14 02:08:34 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	std::cout << "==Original ClapTrap ==" << std::endl << std::endl;
	ClapTrap unknown;

	ClapTrap karl("Karl");

    karl.attack("Dummy");
	unknown.attack("Dummy");
	
	std::cout << std::endl << "==ScavTrap ==" << std::endl << std::endl;
	ScavTrap scavanger("Scavanger");
	ScavTrap anonym;

	
    scavanger.takeDamage(3); // using ClapTrap message
    scavanger.attack("Dummy"); 
	scavanger.beRepaired(2); // using ClapTrap message and has max 10 points now (coz Claptrap inheretence)
	scavanger.guardGate();

	std::cout << std::endl << "==ScavTrap copy and assigment ==" << std::endl << std::endl;
	ScavTrap anonym2 = anonym;
	anonym2.attack("Dummy");
	ScavTrap scavanger2; //starts as "unknown"
	scavanger2.guardGate();
	scavanger2 = scavanger; //should use name "Scavanger"
	scavanger2.guardGate();

	
	std::cout << std::endl << "==Destructors ==" << std::endl << std::endl;

	return 0;
}