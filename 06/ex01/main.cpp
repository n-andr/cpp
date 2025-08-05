/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:01:30 by nandreev          #+#    #+#             */
/*   Updated: 2025/08/05 23:44:41 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Serializer.hpp"
#include <iostream>

/*
implementing a Serializer class for pointer serialization/deserialization, 
which is essentially just type casting between a Data* and an integer type (uintptr_t).

Serialization is taking something in memory 
(like an object or a structure) and turning it into a different format so you can store it or send it.
In our case, we turn a pointer to a Data object into a number (uintptr_t).
*/

int main(){

	std::cout << "Test 1: Data struct with data \n" << std::endl;
	Data data;

	data.id = 42;
	data.name = "Some data";

	std::cout << "Data content -> id: " << data.id
              << ", name: " << data.name << std::endl;
	std::cout << "Original Data address: " << &data << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized value: " << raw << std::endl;
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address: " << ptr << std::endl;
	
	if (ptr == &data)
        std::cout << "Pointers match! ✅" << std::endl;
    else
        std::cout << "Pointers do NOT match! ❌" << std::endl;

    std::cout << "Data content -> id: " << ptr->id
              << ", name: " << ptr->name << std::endl;

	std::cout << "\n\nTest 2: Data struct = NULL \n" << std::endl;
	Data *dataNull = NULL;

	std::cout << "Original Data address: " << dataNull << std::endl;
	raw = Serializer::serialize(dataNull);
	std::cout << "Serialized value: " << raw << std::endl;
	ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address: " << ptr << std::endl;
	
	if (ptr == dataNull)
        std::cout << "Pointers match! ✅" << std::endl;
	else
        std::cout << "Pointers do NOT match! ❌" << std::endl;
	
    return 0;
}