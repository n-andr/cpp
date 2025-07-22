/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:20:30 by nandreev          #+#    #+#             */
/*   Updated: 2025/07/16 23:53:15 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
# define NAME	"Karl"
# define GRADE	42

Bureaucrat::Bureaucrat() : _name(NAME), _grade(GRADE)
{
	//std::cout << "Default constructoor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade){
	//A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade)
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other) this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){}


const std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::incrementGrade(){
		if (_grade - 1 < 1) throw GradeTooHighException();
		_grade--;
}

void Bureaucrat::decrementGrade(){
		if (_grade + 1 > 150) throw GradeTooLowException();
		_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b){
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low!";
}