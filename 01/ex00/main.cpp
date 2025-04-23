/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:51:53 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/24 01:21:50 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(){
	Zombie *zombieObj = newZombie("Heapy");
	zombieObj->announce();
	randomChump("Stacky");

	delete zombieObj;
	return 0;
}