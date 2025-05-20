/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:19:03 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/20 02:18:53 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{ 
	{	
		std::cout	<< "_______________________" << std::endl;
		std::cout	<< "My tests" << std::endl << std::endl;
		
		Animal a;
		//AAnimal aa; //error can't create abstract class;
		
		std::cout	<< "-----Cat from AAnimal-----" << std::endl;

		Cat c;  // can create from AAnimal

		std::cout	<< "-----Dog from AAnimal-----" << std::endl;

		Dog d;  // can create from AAnimal

		std::cout	<< "-----Auto destroy-----" << std::endl;
	}
return 0;
}