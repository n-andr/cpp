/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:19:03 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/20 01:58:05 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{ 
	{
		std::cout	<< "_______________________" << std::endl;
		std::cout	<< "Subject main Animal" << std::endl;

		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl;

		delete j;//should not create a leak
		delete i;
	}
	{
		//In your main function, create and fill an array of Animal objects. 
		//Half of it will be Dog objects and the other half will be Cat objects. 
		//At the end of your program execution, loop over this array and delete every Animal. 
		//You must delete directly dogs and cats as Animals. The appropriate destructors must be called in the expected order.

		std::cout	<< "_______________________" << std::endl;
		std::cout	<< "Subject tests" << std::endl << std::endl;
		
		unsigned int arraySize = 4;
		Animal* animals[arraySize];
		for (unsigned int i = 0; i < arraySize; i++){
			if(i < arraySize/2){
				animals[i] = new Dog();
				static_cast<Dog*>(animals[i])->getBrain()->setIdea(0, "squirrel!squirrel!squirrel!");
			}else {
				animals[i] = new Cat();
				static_cast<Cat*>(animals[i])->getBrain()->setIdea(0, "scratch the couch!");
			}
		}
		for (unsigned int i = 0; i < arraySize; i++){
			delete animals[i];
		}
		
		
	}
	{	
		std::cout	<< "_______________________" << std::endl;
		std::cout	<< "My tests" << std::endl << std::endl;
		
		Dog goldenRetriver;
		goldenRetriver.getBrain()->setIdea(0, "Mmmmm, chicken!");
		goldenRetriver.getBrain()->setIdea(1, "squirrel!squirrel!squirrel!");
		goldenRetriver.getBrain()->setIdea(100, "squirrel!squirrel!squirrel!");

		std::cout	<< "------------" << std::endl;
		std::cout	<< "print brain" << std::endl;
		std::cout << goldenRetriver.getBrain()->getIdea(0) << std::endl;
		std::cout << goldenRetriver.getBrain()->getIdea(1) << std::endl;
		std::cout << goldenRetriver.getBrain()->getIdea(2) << std::endl;
		std::cout << goldenRetriver.getBrain()->getIdea(100) << std::endl;

		//uncomment to print all 100 thoughts 
		// Brain *dogBrain = goldenRetriver.getBrain();

		// for (size_t i = 0; i < 100; i++)
		// {
		// 	std::cout << dogBrain->getIdea(i) << std::endl;
		// }
		
		std::cout	<< "------------" << std::endl;
		std::cout	<< "testing deep copy" << std::endl;
		Dog otherDog = goldenRetriver;
		//std::cout << otherDog.getBrain()->getIdea(0) << std::endl; // otherDog got a copy from goldenRetievers brain
		otherDog.getBrain()->setIdea(2, "I'm a good boi!");	// setting new idea for otherDog, but not for golen
		std::cout << otherDog.getBrain()->getIdea(2) << std::endl; // has idea 2
		std::cout << goldenRetriver.getBrain()->getIdea(2) << std::endl; // doesn't have idea 2
	}
return 0;
}