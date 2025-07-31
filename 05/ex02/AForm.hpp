/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:56:43 by nandreev          #+#    #+#             */
/*   Updated: 2025/08/03 01:13:00 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

//AForm → "Abstract Form". "A"-prefix is a a naming convention. It reminds developers: this class is abstract and should not be instantiated.
//Abstract class: A class that cannot be instantiated, but can be inherited. It contains at least one pure virtual function.

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	//getters
	const std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0; //pure virtual function (has no body, must be overridden)

	//exeptions
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class FormAlreadySignedException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);


#endif