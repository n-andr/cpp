/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:20:56 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/20 02:20:26 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Orthodox Canonical Class Form
must have atleast:
	Default constructor
	Copy constructor
	Copy assignment operator
	Destructor
	

	class Sample {
		private:
			int value;
		public:
			Sample();                            // Default constructor
			Sample(const Sample& other);         // Copy constructor - create an new object
			Sample& operator=(const Sample& other); // Copy assignment operator - assign obj properties to existing obj
			~Sample();                           // Destructor
};

*/

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class  AAnimal // crate AAnimal abstract base class so that nobody can instantiate it -> make at least one of its member functions pure virtual.
{
protected:
	std::string _type;
public:
	// costructours
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);

	// destructor
	virtual ~AAnimal();

	//getter
	std::string getType() const;
	
	virtual void makeSound() const = 0; //pure-virtual → makes Animal abstract
	//pure virtual function is a virtual member function that has no implementation in the base class 
	//and that you must override in any concrete (instantiable) derived class. 
	//You declare it by appending = 0 to its signature
	
};


#endif