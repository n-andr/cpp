/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:16:09 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/14 20:09:28 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// initialize length of the list of contacts

PhoneBook::PhoneBook() : listLength(0) {}

std::string formatField(std::string field){
	if (field.length() > FIELD_DISPLAY_LENGHT)
		return field.substr(0, (FIELD_DISPLAY_LENGHT - 1)) + ".";
	else
		return std::string(FIELD_DISPLAY_LENGHT - field.length(), ' ') + field;
}

// check if there is any content in the input
// isspace() function checks if c is a whitespace character 
// including tabs spaces etc

bool isBlank(const std::string& str) {
    for (std::size_t i = 0; i < str.length(); ++i)
        if (!std::isspace(static_cast<unsigned char>(str[i])))
            return false;
	std::cout << "Error: field cannot be empty.\n";
    return true;
}

bool isDigits(const std::string& str) {
    for (std::size_t i = 0; i < str.length(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(str[i]))){
			std::cout << "Error: must only be digits.\n";
			return false;
		}
    return true;
}

void PhoneBook::addContact(){
	Contact newContact;
	std::string input;
	//create new contact
	//check how many contacts exis, then add or replace
	do {
		std::cout << "Enter First Name: ";
		std::getline(std::cin, input);
	} while (isBlank(input));
	newContact.setFirstName(input);

	do {
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, input);
	} while (isBlank(input));
	newContact.setLastName(input);
	
	do {
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, input);
	} while (isBlank(input));
	newContact.setNickname(input);

	do {
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, input);
	} while (isBlank(input) || !isDigits(input)); //add check if number
	newContact.setPhoneNumber(input);

	do {
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, input);
	} while (isBlank(input));
	newContact.setDarkestSecret(input);

	if (listLength == MAX_CONTACTS) {
		for (int i = 0; i < (MAX_CONTACTS - 1); i ++) {
			contactList[i] = contactList[i + 1];
		}
		contactList[MAX_CONTACTS - 1] = newContact;
	} else {
		contactList[listLength] = newContact;
		listLength ++;
	}
	std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook::displayContactList(){
	std::cout << formatField("Index") 
		<< "|" << formatField("First Name") 
		<< "|" << formatField("Last name") 
		<< "|" << formatField("Nickname") 
		<< std::endl;

	for (int i = 0; i < listLength; i++)
	{
		std::cout << formatField(std::to_string(i))
				<< "|" << formatField(contactList[i].getFirstName())
				<< "|" << formatField(contactList[i].getLastName())
				<< "|" << formatField(contactList[i].getNickname())
				<< std::endl;
	}
	
}


// wait user input with promt "Enter a number from 0 to 7 to access contact information", how do i do it?
	// error check, if input is valid (from 0- to 7, a digit) else "Only numbers 0 - 7", if no contact "This contact doesn't exist"
	// display the contact information, one field per line.

void PhoneBook::search(){
	if (listLength == 0) {
		std::cout << "PhoneBook is empty" << std::endl;
		return;
	}
	displayContactList();
	
	std::string input;
	std::cout << "Enter a number from 0 to 7 to access contact information: ";
	std::getline(std::cin, input);
	if (input.length() == 1 && std::isdigit(input[0]))
	{
		int index = std::stoi(input);
		if (index >= 0 && index < MAX_CONTACTS ){
			if (index >= 0 && index < listLength) {
				std::cout << "First Name: " << contactList[index].getFirstName() << std::endl;
				std::cout << "Last Name: " << contactList[index].getLastName() << std::endl;
				std::cout << "Nickname: " << contactList[index].getNickname() << std::endl;
				std::cout << "Phone Number: " << contactList[index].getPhoneNumber() << std::endl;
				std::cout << "Darkest Secret: " << contactList[index].getDarkestSecret() << std::endl;
			} else {
				std::cout << "This contact doesn't exist yet" << std::endl;
			}
		} else {
			std::cout << "Only numbers 0 - 7" << std::endl;
		}
	} else {
		std::cout << "Only numbers 0 - 7" << std::endl;
	}
	
	
	
}