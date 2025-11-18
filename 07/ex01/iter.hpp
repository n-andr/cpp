/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:48:10 by nandreev          #+#    #+#             */
/*   Updated: 2025/11/18 21:51:47 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstddef> // std::size_t

// simplified version of the STL algorithm std::for_each

// Non-const: allows the callable to modify elements
template<typename T, typename F>
void iter(T *array, const std::size_t len, F f){
	for (std::size_t i = 0; i < len; ++i){
		f(array[i]);
	}
}

// Const: works with const arrays
template<typename T, typename F>
void iter(const T *array, const std::size_t len, F f){
	for (std::size_t i = 0; i < len; ++i){
		f(array[i]);
	}
}

#endif