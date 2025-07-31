/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:40:11 by nandreev          #+#    #+#             */
/*   Updated: 2025/08/01 00:18:48 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other){
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!(this->getIsSigned())) throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute()) throw AForm::GradeTooHighException();
	
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file) throw std::runtime_error("Failed to create a shrubbery file.");
	
	file << "               ,@@@@@@@,\n"
     << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
     << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
     << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
     << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
     << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
     << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
     << "       |o|        | |         | |\n"
     << "       |.|        | |         | |\n"
     << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";

	file.close();
}