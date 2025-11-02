/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:56:47 by nandreev          #+#    #+#             */
/*   Updated: 2025/08/08 15:56:14 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() 
	: _name("Sample Form"), _isSigned(false), _gradeToSign(150),  _gradeToExecute(150)
	{}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150) throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	}

Form& Form::operator=(const Form& other){
	if(this != &other) _isSigned = other._isSigned; // copy only non-const member, const members can't be changed
	return *this;
}

Form::~Form(){}

const std::string Form::getName() const{
	return _name;
}

bool Form::getIsSigned() const{
	return _isSigned;
}

int Form::getGradeToSign() const{
	return _gradeToSign;
}

int Form::getGradeToExecute() const{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat){
	if (this->_isSigned) throw Form::FormAlreadySigned();
	if (bureaucrat.getGrade() > this->_gradeToSign) throw Form::GradeTooHighException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Form grade too low!";
}

const char* Form::FormAlreadySigned::what() const throw(){
	return "Form is already signed!";
}

std::ostream& operator<<(std::ostream& out, const Form& form){
	out << "Form \"" << form.getName()
		<< "\", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
	return out;
}

