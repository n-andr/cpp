/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:48:10 by nandreev          #+#    #+#             */
/*   Updated: 2025/11/04 23:51:03 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

//don’t need a “same-type check”
//—the function template signature already enforces it at compile time
// both params are the same T

template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const& min(const T& a, const T& b)
{
	return (a < b ? a : b); //returns the smallest one. If they are equal, it returns the second one.
}

template<typename T>
T const& max(const T& a, const T& b)
{
	return (a > b ? a : b); //returns the biggest one. If they are equal, it returns the second one.
}


#endif