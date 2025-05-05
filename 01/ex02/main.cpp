/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:51:53 by nandreev          #+#    #+#             */
/*   Updated: 2025/04/28 16:48:23 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

/*
Pointers: 
A pointer is a variable that holds the memory address of another variable. 
A pointer needs to be dereferenced with the * operator to access the memory location it points to. 

References: 
A reference variable is an alias, that is, another name for an already existing variable. 
A reference, like a pointer, is also implemented by storing the address of an object. 
A reference can be thought of as a constant pointer



*/
int main(){
	std::string str = "HI THIS IS BRAIN";
	
	// A pointer to variable i or "stores the address of str"
	std::string *stringPTR = &str;

	// A reference (or alias) for str
	std::string &stringREF = str;
	
	// Print address points to
	std::cout << "string address is:   " << &str << std::endl;
	std::cout << "stringPTR points to: " << stringPTR << std::endl;
	std::cout << "stringREF points to: " << &stringREF << std::endl;

	// Print it's own adress (not part of the task)
	// std::cout << "string address:   " << &str << std::endl;
	// std::cout << "stringPTR adress: " << &stringPTR << std::endl;
	// std::cout << "stringREF adress: " << &stringREF << std::endl;
	
	// Print value
	std::cout << "string value is:   " << str << std::endl;
	std::cout << "stringPTR value to: " << *stringPTR << std::endl;
	std::cout << "stringREF value to: " << stringREF << std::endl;

	return 0;
}