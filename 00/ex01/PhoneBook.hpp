/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 01:12:44 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/14 19:36:37 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>
# include <limits>
# include <cctype> // for std::isspace, std::isdigit


# define MAX_CONTACTS 8
# define FIELD_DISPLAY_LENGHT 10


class PhoneBook {
	public:
		PhoneBook();
		void addContact();
		void search();
		//void exit();
		void displayContactList();
	private:
		Contact contactList[MAX_CONTACTS];
		int listLength;
};

#endif