/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:41:44 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/14 18:12:47 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

// attributes are private, we don't want everyone to know the darkest secrets :) 

class	Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		
	public:
		//getters
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		
		//setters
		void setFirstName(const std::string str);
		void setLastName(const std::string str);
		void setNickname(const std::string str);
		void setPhoneNumber(const std::string str);
		void setDarkestSecret(const std::string str);
};

#endif