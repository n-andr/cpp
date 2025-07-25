/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:40:19 by nandreev          #+#    #+#             */
/*   Updated: 2025/07/25 02:07:13 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){

	
	Bureaucrat intern("John PleaseComeBackLater", 150);
	Bureaucrat bigBoss("Mr. Papers", 1);
	Form* passportForm = NULL;

	std::cout << "\n\nTest create Forms:\n  1.Success\n  2.Fail\n  3.Fail\n  4.Fail\n  5.Fail\n" << std::endl;
	try{
		passportForm = new Form("Passport form", 30, 50);
		std::cout << *passportForm << std::endl;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try{
		Form passportForm1("Passport form", 0, 50);
		std::cout << passportForm1 << std::endl;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try{
		Form passportForm2("Passport form", 151, 50);
		std::cout << passportForm2 << std::endl;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try{
		Form passportForm3("Passport form", 10, 0);
		std::cout << passportForm3 << std::endl;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try{
		Form passportForm2("Passport form", 10, 151);
		std::cout << passportForm2 << std::endl;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\nTest sign Forms:\n  1.Fail: form not signed \n  2.Success: form is signed\n" << std::endl;
	try
	{
		intern.signForm(*passportForm);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *passportForm << std::endl;
	try
	{
		bigBoss.signForm(*passportForm);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *passportForm << std::endl;
	
	std::cout << "\n\nTest: try to sign already signed form\n  1.Fail: form already signed\n" << std::endl;
	try
	{
		bigBoss.signForm(*passportForm);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *passportForm << std::endl;
	
	std::cout << "\n\nTest: Copy assignment operator. Keeps grade to sign and grade to execute\n" << std::endl;
	Form dummyPass("DummyPass", 100, 100);
	dummyPass = *passportForm;
	std::cout << dummyPass << std::endl;

	if (passportForm)	delete passportForm;
	
}