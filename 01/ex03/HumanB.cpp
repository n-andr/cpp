/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:38:43 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/05 21:53:18 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/HumanB.hpp"

HumanB::HumanB(std::string humanName): name(humanName), weapon(NULL){}

void	HumanB::attack(){
	if(weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weaponName){
	weapon = &weaponName;
}