/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:20:56 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/17 22:57:27 by nandreev         ###   ########.fr       */
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

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class  WrongAnimal
{
protected:
	std::string _type;
public:
	// costructours
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);

	// destructor
	virtual ~WrongAnimal();

	//getter
	std::string getType() const;
	
	void makeSound() const; //not virtual so is called at compile time, and wont be overwritten by WrongCat
};


#endif