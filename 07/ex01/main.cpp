/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:48:16 by nandreev          #+#    #+#             */
/*   Updated: 2025/11/05 00:59:22 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


//test finction to be called upon array
template<typename T>
void printT(T &el){
	std::cout << el << std::endl;
}

int main( void ) 
{
	int nums[] = {1, 2, 3};
	//need to specify the template argument there (e.g., &printT<int>) because passing a function pointer 
	// and a function template isn’t a function until pick its type parameters.
	iter(nums, 3, &printT<int>);
	std::string words[] = {"hi", "there"};
	iter(words, 2, &printT<std::string>);
}

