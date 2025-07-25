/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:40:19 by nandreev          #+#    #+#             */
/*   Updated: 2025/07/23 01:26:47 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){

	std::cout << "\n\nTest John:\n1.Decrement grade\n2.Inctrement grade\n3.Throw exeption\n" << std::endl;
	Bureaucrat john("John PleaseComeBackLater", 150);

	try{
		john.incrementGrade();
		std::cout << john << std::endl;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try{
		john.decrementGrade();
		std::cout << john << std::endl;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try{
		john.decrementGrade();
		std::cout << john << std::endl;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\nTest Jess:\n1.Throw exeption\n2.Decrement grade\n" << std::endl;

	Bureaucrat jess("Jess FormCheck", 1);

	try{
		jess.incrementGrade();
		std::cout << jess << std::endl;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try{
		jess.decrementGrade();
		std::cout << jess << std::endl;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	// std::cout << "\n\nTest: call Bureaucrat constructor WITHOUT catching an exeption" << std::endl;
	// Bureaucrat mr("Mr MorePaperwork", -1);
	

	std::cout << "\n\nTest: call Bureaucrat constructor WITH/WITHOUT catching an exeption" << std::endl;
	try
	{
		Bureaucrat mr("Mr MorePaperwork", -1);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\nTest: create Bureaucrat without a name" << std::endl;
	Bureaucrat unknown;
	std::cout << unknown << std::endl;
}