/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:53:39 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/05 21:26:48 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
private:
	std::string type;
public:
	std::string getType();
	void setType(std::string newType);
	Weapon(std::string weaponName);
	~Weapon();
};

// Weapon::Weapon(/* args */)
// {
// }

// Weapon::~Weapon()
// {
// }



#endif