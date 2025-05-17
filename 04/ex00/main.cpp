/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:19:03 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/17 23:20:13 by nandreev         ###   ########.fr       */
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

		const Animal*	meta = new Animal();
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound(); //will output the dog sound!
		meta->makeSound(); //will output the animal sound!

		delete meta;
		delete i;
		delete j;
	}
	{
		std::cout	<< "_______________________" << std::endl;
		std::cout	<< "Subject main WrongAnimal" << std::endl;

		const WrongAnimal*	meta = new WrongAnimal();
		const WrongAnimal*	j = new WrongCat();
		

		std::cout << j->getType() << " " << std::endl;

		meta->makeSound(); //will output the wrong animal sound
		j->makeSound(); //will output the wrong animal sound

		delete meta;
		delete j;
	}
	{	
		std::cout	<< "_______________________" << std::endl;
		std::cout	<< "My main" << std::endl;

		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << animal->getType() << std::endl;
		animal->makeSound();
		
		std::cout << dog->getType() << std::endl;
		dog->makeSound();
		
		std::cout << cat->getType() << std::endl;
		cat->makeSound();
		
		delete animal;
		delete dog;
		delete cat;
	}
	{
		std::cout	<< "_______________________" << std::endl;
		std::cout	<< "My main (inheritance from child to parent (upcasting))" << std::endl;
		Dog*     d  = new Dog();
		Animal*  a1 = d;           // upcast: safe, no slice (pointer to dog)
		Animal&  a2 = *d;          // also safe (reference to dog)
		Animal   a3 = *d;          // slices! a3 is now just an Animal (new animal Object)
	
		a1->makeSound();           // calls Dog::makeSound() if virtual
		a2.makeSound();            // same
		
		std::cout << a3.getType() << std::endl; //still dog
		a3.makeSound();            // calls Animal::makeSound(), Dog sound part lost
		delete d;
	}
return 0;
}