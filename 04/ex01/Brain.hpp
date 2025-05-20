/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 02:20:00 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/19 17:49:31 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
		static const unsigned int	MAX_IDEAS = 100;
		std::string					_ideas[MAX_IDEAS];

	public:
		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);

		~Brain();

		void		setIdea(unsigned int index, const std::string& idea);
		std::string	getIdea(unsigned int index) const;
};



#endif