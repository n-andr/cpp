/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:48:16 by nandreev          #+#    #+#             */
/*   Updated: 2025/11/19 00:22:12 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


//test finction to be called upon array
template<typename T>
void printT(T const &el){
	std::cout << el << std::endl;
}

template<typename T>
void addOne(T &el){
	el++;
}

int main( void ) 
{
	int nums[] = {1, 2, 3};
	std::string words[] = {"hi", "there"};

	//need to specify the template argument there (e.g., &printT<int>) because passing a function pointer 
	// and a function template isn’t a function until pick its type parameters.
	std::cout << "test 1 Print array\n\n";
	iter(nums, 3, printT<int>);
	std::cout << "\n";
	iter(words, 2, printT<std::string>);
	std::cout << "\n";

	std::cout << "test 2 add 1 and print\n\n";
	iter(nums, 3, addOne<int>);
	iter(nums, 3, printT<int>);
	std::cout << "\n";
	//iter(words, 3, addOne<std::string>); //will error on compilation
	//iter(words, 2, printT<std::string>);
	//std::cout << "\n";

	const int constNums[] = {42, 43, 44};
	std::cout << "test 3 const array (read only)\n\n";
	iter(constNums, 3, printT<int>);
	std::cout << "\n";

	double doubles[] = {1.1, 2.2, 3.3};
	std::cout << "test 4 doubles + addOne\n\n";
	iter(doubles, 3, addOne<double>);
	iter(doubles, 3, printT<double>);
	std::cout << "\n";

	int empty[0];
	std::cout << "test 6 empty array (should print nothing)\n\n";
	iter(empty, 0, printT<int>);
	std::cout << "done\n\n";
}

