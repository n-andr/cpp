/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:16:22 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/14 20:24:33 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook myAwesomePhoneBook;
	std::string command;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "The program only accepts ADD, SEARCH and EXIT" << std::endl;

	while (true)
	{
		std::cout << "Enter command: ";
        std::getline(std::cin, command);

		if (command == "ADD"){
			myAwesomePhoneBook.addContact();
		} else if(command == "SEARCH") {
			myAwesomePhoneBook.search();
		} else if(std::cin.eof() || command == "EXIT") {
			std::cout << "Goodbye!" << std::endl;
            break;
		} else
			std::cout << "Unknown command. Please use ADD, SEARCH, or EXIT." << std::endl;
	}
	return 0;
	
}