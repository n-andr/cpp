/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:16:31 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/14 18:13:44 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"



//setters
void Contact::setFirstName(const std::string str) {
	firstName = str;
}

void Contact::setLastName(const std::string str) {
	lastName = str;
}
void Contact::setNickname(const std::string str) {
	nickname = str;
}

void Contact::setPhoneNumber(const std::string str) {
	phoneNumber = str;
}

void Contact::setDarkestSecret(const std::string str) {
	darkestSecret = str;
}



//getters
std::string Contact::getFirstName() {
	return firstName;
}

std::string Contact::getLastName() {
	return lastName;
}

std::string Contact::getNickname() {
	return nickname;
}

std::string Contact::getPhoneNumber() {
	return phoneNumber;
}

std::string Contact::getDarkestSecret() {
	return darkestSecret;
}