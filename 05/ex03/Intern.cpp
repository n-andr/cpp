/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:27:01 by nandreev          #+#    #+#             */
/*   Updated: 2025/08/03 01:00:21 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) {(void)other;}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}



static AForm* createShrubbery(const std::string& target){
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target){
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target){
	return new PresidentialPardonForm(target);
}

struct FormNameFunctionPair
{
	std::string name;
	AForm* (*createtorFunc)(const std::string& target);
};

AForm* Intern::makeForm(const std::string& name, const std::string& target){
	const FormNameFunctionPair formMap[] = {
		{ "shrubbery creation",  createShrubbery },
    	{ "robotomy request",    createRobotomy },
    	{ "presidential pardon", createPresidential }
	};

	int mapLen = 3;
	
	for (int i = 0; i < mapLen; i++)
	{
		if (name == formMap[i].name){
			std::cout << "Intern creates " << name << std::endl;
			return formMap[i].createtorFunc(target);
		}
	}
	std::cout << "Intern: No form '" << name << "'found." << std::endl;
	return NULL;
	
}
