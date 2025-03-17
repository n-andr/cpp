#include "Contact.hpp"

void Contact::fillContact()
{
	std::string input;

	// First name
	do {
		std::cout << "Enter First Name: "; 
		std::getline(std::cin, input);
	} while (input.empty());
	firstName = input;

	// Last Name
    do {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
    } while (input.empty());
    lastName = input;

    // Nickname
    do {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, input);
    } while (input.empty());
    nickname = input;

    // Phone Number
    do {
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, input);
    } while (input.empty());
    phoneNumber = input;

    // Darkest Secret
    do {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
    } while (input.empty());
    darkestSecret = input;
}