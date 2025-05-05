/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:53:09 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/05 19:54:36 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Weapon.hpp"

std::string Weapon::getType(){
	return type;
}

void Weapon::setType(std::string newType){
	type = newType;
}

Weapon::Weapon(std::string weaponName){
	type = weaponName;
}

Weapon::~Weapon(){}

