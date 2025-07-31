/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:56:47 by nandreev          #+#    #+#             */
/*   Updated: 2025/07/29 23:01:03 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() 
	: _name("Sample Form"), _isSigned(false), _gradeToSign(150),  _gradeToExecute(150)
	{}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	}

AForm& AForm::operator=(const AForm& other){
	if(this != &other) _isSigned = other._isSigned; // copy only non-const member, const members can't be changed
	return *this;
}

AForm::~AForm(){}

const std::string AForm::getName() const{
	return _name;
}

bool AForm::getIsSigned() const{
	return _isSigned;
}

int AForm::getGradeToSign() const{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat& bureaucrat){
	if (this->_isSigned) throw AForm::FormAlreadySignedException();
	if (bureaucrat.getGrade() > this->_gradeToSign) throw AForm::GradeTooHighException();
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Form grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Form grade too low!";
}

const char* AForm::FormAlreadySignedException::what() const throw(){
	return "Form is already signed!";
}

const char* AForm::FormNotSignedException::what() const throw(){
	return "Form is not signed! It cant be executed";
}

std::ostream& operator<<(std::ostream& out, const AForm& form){
	out << "Form \"" << form.getName()
		<< "\", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
	return out;
}

