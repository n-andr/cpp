/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:41:16 by nandreev          #+#    #+#             */
/*   Updated: 2025/11/20 23:43:26 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <string>
#include "Array.hpp"

int main(){
	
	// int *a = new int();
	// std::cout << *a << std::endl;

	// std::string *arr = new std::string[5]();
	// std::cout << *arr << std::endl;

	// int *arr = new int[5]();

	// for (unsigned long i = 0; i < arr->size(); i++)
	// 	std::cout << arr[i] << std::endl;

	std::cout << "---- Test: create array ----" << std::endl;
	std::cout << "------- Test: create an empty array" << std::endl;
	
	Array <int> empty;
	std::cout << "size: " << empty.size() << std::endl;
    try {
        empty[0];
    } catch (std::exception &e) {
        std::cout << "Caught exception on tryong to access empty[0] (expected): " << e.what() << std::endl;
    }
	
	std::cout << "\n------- Test 1b: create array with 5 0-ed ints" << std::endl;
    Array<int> ints(5);
    std::cout << "size: " << ints.size() << std::endl;
    for (unsigned int i = 0; i < ints.size(); i++)
       { std::cout << "ints[" << i << "] = " << ints[i] << std::endl;}

	
	std::cout << "\n------- Test 1c: create array with 3 empty strings" << std::endl;
    Array<std::string> words(3);
    for (unsigned int i = 0; i < words.size(); i++)
        {std::cout << "words[" << i << "] = \"" << words[i] << "\"" << std::endl;}


	std::cout << "\n---- Test 2: write and read ----" << std::endl;
	std::cout << "\n------- Test 2a: populate int-array" << std::endl;
    for (unsigned int i = 0; i < ints.size(); i++)
       { ints[i] = static_cast<int>(i * 10);}
    for (unsigned int i = 0; i < ints.size(); i++)
        {std::cout << "ints[" << i << "] = " << ints[i] << std::endl;}

	std::cout << "\n------- Test 2a: populate string-array" << std::endl;
    words[0] = "hello";
    words[1] = "template";
    words[2] = "world";
    for (unsigned int i = 0; i < words.size(); i++)
        {std::cout << "words[" << i << "] = " << words[i] << std::endl;}

	std::cout << "\n---- Test 3: copy constructor ----" << std::endl;
    Array<int> copyInts(ints);
    std::cout << "Copy created. Modifying copyInts" << std::endl;
    copyInts[0] = 999;
    std::cout << "ints[0] = " << ints[0] << ", copyInts[0] = " << copyInts[0] << std::endl;
    std::cout << "(They should differ if deep copy is correct)" << std::endl;
	
	std::cout << "\n---- Test 4: assignment operator ----" << std::endl;
    Array<std::string> otherWords;
    otherWords = words;
    std::cout << "Copy assigned. Modifying otherWords" << std::endl;
    otherWords[0] = "modified";
    std::cout << "words[0] = " << words[0] << ", otherWords[0] = " << otherWords[0] << std::endl;

    std::cout << "\n---- Test 5: self-assignment safety ----" << std::endl;
    //ints = ints;
    std::cout << "Self-assignment is impossible" << std::endl;

	std::cout << "\n---- Test 6: bounds checking ----" << std::endl;
    try {
        std::cout << "Accessing index 10 (should throw)..." << std::endl;
        std::cout << ints[10] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

	std::cout << "\n---- Test 7: const correctness ----" << std::endl;
    const Array<int> constInts(ints);
    std::cout << "constInts.size() = " << constInts.size() << std::endl;
    for (unsigned int i = 0; i < constInts.size(); i++)
        {std::cout << "constInts[" << i << "] = " << constInts[i] << std::endl;}

	std::cout << "\n---- Test 8: nested arrays ----" << std::endl;
    Array< Array<int> > matrix(2);
    matrix[0] = ints;
    matrix[1] = copyInts;
    for (unsigned int i = 0; i < matrix.size(); i++) {
        std::cout << "matrix[" << i << "]: ";
        for (unsigned int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }


	std::cout << "\n---- Test 9: very large array ----" << std::endl;
	try {
		const unsigned int BIG_SIZE = 10000000; // 10 million
		std::cout << "Creating array of " << BIG_SIZE << " ints" << std::endl;
		Array<int> big(BIG_SIZE);
		std::cout << "Size = " << big.size() << std::endl;
		big[0] = 1;
		big[BIG_SIZE - 1] = BIG_SIZE;
		std::cout << "Edge elements: first=" << big[0] 
				<< ", last=" << big[BIG_SIZE - 1] << std::endl;
		//uncomment to print all 10 million entries (all 0 exept the first and last one)
		// for (unsigned int i = 0; i < big.size(); i++)
        // 	std::cout << "big[" << i << "] = " << big[i] << " ";
	} catch (std::bad_alloc &e) {
		std::cout << "Allocation failed: " << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Other exception: " << e.what() << std::endl;
	}

	//when an object goes out of scope, its destructor is called automatically.
}