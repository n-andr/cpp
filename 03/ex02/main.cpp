/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:19:03 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/14 02:55:39 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
	std::cout << "==Original ClapTrap ==" << std::endl << std::endl;
	ClapTrap unknown;

	ClapTrap karl("Karl");

    karl.attack("Dummy");
	unknown.attack("Dummy");

	std::cout << std::endl << "==FragTrap copy and assigment ==" << std::endl << std::endl;
	FragTrap anonym;
	anonym.attack("Dummy"); // msg says claptrap, but points are from fragtrap
	FragTrap trap("Trap"); 
	trap.highFivesGuys();
	
	std::cout << std::endl << "==Destructors ==" << std::endl << std::endl;

	return 0;
}