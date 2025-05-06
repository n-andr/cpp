/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:56:20 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/06 22:57:58 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon& weaponName): name(humanName), weapon(weaponName){}

void	HumanA::attack(){
	std::cout << name << " attacks with " << weapon.getType() << std::endl;
}