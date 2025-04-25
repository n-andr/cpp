/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:51:53 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/25 10:10:58 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie*    zombieHorde( int N, std::string name );

int main(){
	int n = 5;
	Zombie *zombieArray = zombieHorde(n, "Karl");
	for (int i = 0; i < n; i++)
	{
		zombieArray[i].announce();
	}
	delete[] zombieArray;
	return 0;
}