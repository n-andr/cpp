/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:21:25 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/25 10:10:13 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name ){
	if (N <= 0)
        return 0;    
	Zombie *horde = new Zombie[N]; 
	for (size_t i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return horde;
}