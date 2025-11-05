/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:58:06 by nandreev          #+#    #+#             */
/*   Updated: 2025/11/05 12:43:44 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// runtime type identification without typeid()
// use dynamic_cast to figure out whether an object is really an A, B, or C

#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"
#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>	// for std::time()

// It randomly instantiates A, B, or C and 
// returns the instance as a Base pointer.
Base * generate(void){

	int randomValue = std::rand() % 3;
	
	if (randomValue == 0)
    {
        std::cout << "Generated: A" << std::endl;
        return new A();
    }
    else if (randomValue == 1)
    {
        std::cout << "Generated: B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated: C" << std::endl;
        return new C();
    }
}

//It prints the actual type of the object pointed to by p: "A", "B", or "C".

/* 
dynamic_cast behaves different depending on whether casting a pointer or a reference.

Pointer:
If the cast succeeds → returns a valid pointer to the derived type.
If the cast fails → returns NULL (0).
No exception is thrown, so you can just check if the result is NULL or not. 

failure → NULL → check directly with if.
*/

void identify(Base* p){
	std::cout << "Poiner to" << std::endl;
	if (dynamic_cast<A*>(p)) std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B*>(p)) std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C*>(p)) std::cout << "Type C" << std::endl;
	else std::cout << "Unknown Type" << std::endl;
}

// It prints the actual type of the object referenced by p: "A", "B", or "C"

/* 
dynamic_cast behaves different depending on whether casting a pointer or a reference.

Reference:
If the cast succeeds → returns a valid reference to the derived type.
If the cast fails → cannot return “null reference” (null references don’t exist in C++),
so it throws a std::bad_cast exception instead.
That’s why we must wrap it in a try { ... } catch (...) {} block.

failure → exception → must catch it.
*/

void identify(Base& p){
	std::cout << "Reference to: " << std::endl;
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
		return;
	} catch (...) {}

	std::cout << "Unknown type" << std::endl;
	
}

class D : public Base {};

int main(){
	std::srand(std::time(0));
	Base* randomBase = generate();

	identify(randomBase);
	if (randomBase) identify(*randomBase); // cant dereference NULL would crash

	delete randomBase;

	std::cout << "\n--- Multiple Tests ---" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* temp = generate();
        identify(temp);
        if (temp) identify(*temp);
        delete temp;
        std::cout << std::endl;
    }

	std::cout << "\n--- Unknown ---" << std::endl;

	randomBase = new D();
	identify(randomBase);
	identify(*randomBase);

	delete randomBase;

	return 0;
	
}