/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:51:49 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/24 01:11:17 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// It creates a zombie, names it, and the zombie announces itself.

	// created on the *stack*
	// scope ends after obj.announce();  — destructor runs automatically

void randomChump( std::string name ){
	Zombie obj(name);
	obj.announce();
}