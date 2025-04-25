/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:51:32 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/25 10:06:33 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>


class Zombie {
	private:
		std::string name;

	public:
		Zombie();
		void announce(void);
		void setName(std::string newName);
		~Zombie(); //destractor
};



#endif