/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:40:19 by nandreev          #+#    #+#             */
/*   Updated: 2025/08/07 19:05:07 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <time.h>

int main(){

	std::srand(time(NULL)); //for rand() use current time as seed for random generator
	Bureaucrat junior("John PleaseComeBackLater", 150);
	Bureaucrat bigBoss("Mrs. Papers", 1);
	
	{
		ShrubberyCreationForm tree("home");
		
		std::cout << "\n\nTest create ShrubberyCreationForm:\n  1.Fail : Form is not signed" << std::endl;
		try
		{
			bigBoss.executeForm(tree);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n\nTest create ShrubberyCreationForm:\n  1.Fail : can't sign" << std::endl;

		try
		{
			junior.signForm(tree);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n\nTest create ShrubberyCreationForm:\n  1.Fail : can't execute" << std::endl;

		try
		{
			bigBoss.signForm(tree);
			junior.executeForm(tree);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n\nTest create ShrubberyCreationForm:\n  1.Success, file should be created" << std::endl;

		try
		{
			bigBoss.executeForm(tree);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}


	//RobotomyRequestForm
	{
		RobotomyRequestForm robo("home");
		
		std::cout << "\n\nTest create RobotomyRequestForm:\n  1.Fail : Form is not signed" << std::endl;
		try
		{
			bigBoss.executeForm(robo);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n\nTest create RobotomyRequestForm:\n  1.Fail : can't sign" << std::endl;

		try
		{
			junior.signForm(robo);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n\nTest create RobotomyRequestForm:\n  1.Fail : can't execute" << std::endl;

		try
		{
			bigBoss.signForm(robo);
			junior.executeForm(robo);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n\nTest create RobotomyRequestForm:\n  1.Success, robotomy should start" << std::endl;

		try
		{
			bigBoss.executeForm(robo);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

		//PresidentialPardonForm
	{
		PresidentialPardonForm robo("home");
		
		std::cout << "\n\nTest create PresidentialPardonForm:\n  1.Fail : Form is not signed" << std::endl;
		try
		{
			bigBoss.executeForm(robo);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n\nTest create PresidentialPardonForm:\n  1.Fail : can't sign" << std::endl;

		try
		{
			junior.signForm(robo);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n\nTest create PresidentialPardonForm:\n  1.Fail : can't execute" << std::endl;

		try
		{
			bigBoss.signForm(robo);
			junior.executeForm(robo);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n\nTest create PresidentialPardonForm:\n  1.Success" << std::endl;

		try
		{
			bigBoss.executeForm(robo);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	
	// try{
	// 	passportForm = new AForm("Passport form", 30, 50);
	// 	std::cout << *passportForm << std::endl;
	// } catch(std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// if (passportForm)	delete passportForm;
	
}