/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:19:03 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/13 02:39:48 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
	ClapTrap unknown;

	ClapTrap karl("Karl");

    karl.attack("Dummy");
    karl.takeDamage(3);
    karl.beRepaired(2);
	karl.beRepaired(2);
	karl.beRepaired(2);

    // drain energy
    for (int i = 0; i < 11; ++i)
        karl.attack("Looser");

    // blow it up
    karl.takeDamage(20);
    karl.attack("Nope");
    karl.beRepaired(5);

	
	
	return 0;
}