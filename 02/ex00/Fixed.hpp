/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:20:56 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/12 00:58:12 by nandreev         ###   ########.fr       */
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

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class  Fixed
{
private:
	int fixPointNumber;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
};


#endif