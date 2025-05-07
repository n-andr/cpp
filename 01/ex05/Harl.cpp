/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:08:28 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/07 02:50:14 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

void	Harl::debug() {
	std::cout << "[DEBUG] " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
	std::cout << "[INFO] " << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cerr << "[WARNING] " << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error() {
	std::cerr << "[ERROR] " << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void	Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	bool levelFound = false;
	
	void (Harl::*levelPtrs[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (size_t i = 0; i < 4; ++i){
		if (level == levels[i])
		{
			(this->*levelPtrs[i])();
			levelFound = true;
			break;
		}
	}
	if (!levelFound)
	std::cerr << "Level does not exist: " << level << std::endl;
}