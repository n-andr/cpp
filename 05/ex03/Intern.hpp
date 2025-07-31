/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:26:56 by nandreev          #+#    #+#             */
/*   Updated: 2025/08/02 00:09:29 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP


#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern
{

public:
	Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

	AForm* makeForm(const std::string& name, const std::string& target);
};


#endif