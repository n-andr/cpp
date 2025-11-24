#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	// ==============================================================  
	// Test 1 — Subject Test  
	// ==============================================================  
	std::cout << "\n=== TEST 1: SUBJECT TEST ===" << std::endl;

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Stored numbers: 6, 3, 17, 9, 11" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	} 
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// ==============================================================  
	// Test 2 — Exception: Adding too many numbers  
	// ==============================================================  
	std::cout << "\n=== TEST 2: EXCEPTION ON ADDING TOO MANY NUMBERS ===" << std::endl;

	try {
		Span sp(3);
		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);

		std::cout << "Attempting to add a 4th number..." << std::endl;
		sp.addNumber(40); // should throw
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// ==============================================================  
	// Test 3 — Exception: Not enough numbers to get spans  
	// ==============================================================  
	std::cout << "\n=== TEST 3: EXCEPTION ON TOO SMALL SPAN ===" << std::endl;

	try {
		Span sp(10);
		sp.addNumber(42);
		std::cout << "Attempting shortestSpan() with only 1 number..." << std::endl;
		std::cout << sp.shortestSpan() << std::endl; // should throw
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// ==============================================================  
	// Test 4 — Negative Numbers  
	// ==============================================================  
	std::cout << "\n=== TEST 4: NEGATIVE NUMBERS ===" << std::endl;

	try {
		Span sp(6);
		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(0);
		sp.addNumber(3);
		sp.addNumber(50);
		sp.addNumber(-7);

		std::cout << "Stored: -10, -5, 0, 3, 50, -7" << std::endl;

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// ==============================================================  
	// Test 5 — Bulk add using range  
	// ==============================================================  
	std::cout << "\n=== TEST 5: BULK RANGE ADD ===" << std::endl;

	try {
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 3); // 0, 3, 6, ...

		Span sp(20);
		sp.addRange(vec.begin(), vec.end());

		std::cout << "Added numbers: ";
		for (unsigned int i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// ==============================================================  
	// Test 6 — Large random test  
	// ==============================================================  
	std::cout << "\n=== TEST 6: LARGE RANDOM TEST (10,000 numbers) ===" << std::endl;

	try {
		std::srand(std::time(NULL));

		Span sp(10000);
		for (int i = 0; i < 10000; i++)
			sp.addNumber(std::rand());

		std::cout << "Random numbers added." << std::endl;

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// ==============================================================  
	// Done  
	// ==============================================================  
	std::cout << "\n=== END OF ALL TESTS ===\n" << std::endl;

	return 0;
}