/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:22:32 by nandreev          #+#    #+#             */
/*   Updated: 2025/07/30 00:50:01 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other){
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (!(this->getIsSigned())) throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute()) throw AForm::GradeTooHighException();
	
	std::cout << "* DRILLING NOISES * VRRRRRRRRT *\n";
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!\n";
	else
		std::cout << "Robotomy failed for " << _target << "!\n";

	
}