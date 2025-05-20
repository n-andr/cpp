/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:40:34 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/20 00:57:35 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor was called" << std::endl;
	for (unsigned int i = 0; i < MAX_IDEAS; i++)
	{
		_ideas[i] = "No idea in this slot";
	}
}

Brain::Brain(const Brain& other){
	std::cout << "Brain copy constructor was called" << std::endl;

	for(unsigned int i = 0; i < MAX_IDEAS; i++){
		_ideas[i] = other._ideas[i];
	}
}

Brain&	Brain::operator=(const Brain& other){
	std::cout << "Brain assigment operatour was called" << std::endl;
	if(this != &other){
		for(unsigned int i = 0; i < MAX_IDEAS; i++){
		_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain(){
	std::cout << "Brain destructor was called" << std::endl;
}

void	Brain::setIdea(unsigned int index, const std::string& idea){
	if (index < MAX_IDEAS) {
		_ideas[index] = idea;
	} else {
		std::cout << "Brain can only have 100 ideas" << std::endl;
	}
}

std::string	Brain::getIdea(unsigned int index) const{
	if (index < MAX_IDEAS)
		return _ideas[index];
	return "Brain can only have 100 ideas";
}