/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:41:13 by nandreev          #+#    #+#             */
/*   Updated: 2025/11/20 22:37:20 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>	// for std::exception

template <typename T>
class Array
{
	private:
		T* _data;
		unsigned int _size;
		
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);  // Copy constructor - create an new object
		Array &operator=(const Array &other); // Copy assignment operator - assign obj properties to existing obj
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
		~Array();

		unsigned int size() const;

		class OutOfBoundException : public std::exception {
			public:
        		const char* what() const throw();
		};
};

# include "Array.tpp"

#endif