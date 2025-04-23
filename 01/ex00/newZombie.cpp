/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:51:46 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/24 01:11:07 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//It creates a zombie, name it, and return it 
//so you can use it outside of the function scope.

 	// allocate on the *heap*
    // and return pointer so the caller decides when to delete

Zombie* newZombie( std::string name ){
	Zombie* obj = new Zombie(name);
	return obj;
}