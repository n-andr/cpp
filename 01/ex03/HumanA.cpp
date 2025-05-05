/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:56:20 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/05 21:50:49 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon& weaponName): name(humanName), weapon(weaponName){}

void	HumanA::attack(){
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}