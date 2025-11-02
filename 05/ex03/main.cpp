/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:40:19 by nandreev          #+#    #+#             */
/*   Updated: 2025/08/08 15:56:50 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <time.h>

int main(){

	std::srand(time(NULL)); //for rand() use current time as seed for random generator
	Bureaucrat junior("John PleaseComeBackLater", 150);
	Bureaucrat boss("Mrs. Papers", 1);
	Intern karl;
	
	std::cout << "\n--- Intern creates valid forms ---\n" << std::endl;

	//karl.makeForm("robotomy request", "Bender"); //should create memory leak
	
	AForm* pardon = karl.makeForm("presidential pardon", "Mr. Innocent");
	AForm* shrubbery = karl.makeForm("shrubbery creation", "Backyard");
	AForm* robotomy = karl.makeForm("robotomy request", "Bender");

	std::cout << "\n--- Signing and Executing Forms ---\n" << std::endl;

    if (shrubbery) {
        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);
    }

    if (robotomy) {
        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);
    }

    if (pardon) {
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
    }

	std::cout << "\n--- Intern fails ---\n" << std::endl;

	AForm* unknown = karl.makeForm("abc", "xyz");

	if(shrubbery) delete shrubbery;
	if(pardon) delete pardon;
	if(robotomy) delete robotomy;
	if(unknown) delete unknown;
	
}