#include "easyfind.hpp"
#include <iostream>
#include <vector>       // std::vector
#include <numeric> 		//for itoa
#include <list>			//list
#include <deque>		//deque



int main(){
	std::cout << "\n\n";
	{
		std::vector<int> vectorContainer(10);

		std::iota (std::begin(vectorContainer), std::end(vectorContainer), 10); //Fill with 10, 11, ..., 19
		std::cout << "Vector Container has:";
		for (int i = 0; vectorContainer[i]; i++) std::cout << " " << vectorContainer[i];
		std::cout << "\n";
		try{
			//value found -> print to which valie is iterator pointing
			std::cout << "Searching for 13" << std::endl;
			std::vector<int>::iterator it = easyfind(vectorContainer, 13); 
			std::cout << "Element found: " << *it << std::endl;

			//value not found -> exeption error
			std::cout << "Searching for 130"<< std::endl;
			it = easyfind(vectorContainer, 130);
			std::cout << "Element found: " << *it << std::endl;
		} catch (const std::runtime_error& e) {
			std::cerr << e.what() <<std::endl;
		}

		try{
			std::cout << "add 130 to container and try again"<< std::endl;
			vectorContainer.push_back(130);
			//value found -> print to which valie is iterator pointing
			std::cout << "Searching for 130"<< std::endl;
			std::vector<int>::iterator it = easyfind(vectorContainer, 130);
			std::cout << "Element found: " << *it << std::endl;
			std::cout << "Inserting 999 before element 130 (usung iterator from easyfind)" << std::endl;
			vectorContainer.insert(it, 999); //The returned iterator becomes invalid after insertion
			std::cout << "Updated Vector:";
			for (int i = 0; vectorContainer[i]; i++) std::cout << " " << vectorContainer[i];
			std::cout << "\n";
		} catch (const std::runtime_error& e) {
			std::cerr << e.what() <<std::endl;
		}
	}
	std::cout << "\n\n";
	{
		std::list<int> l;
		l.push_back(7);
		l.push_back(5);
		l.push_back(16);
		l.push_back(8);
		std::cout << "List Container has:";
		for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
			std::cout << " " << *it;
		}
		std::cout <<"\n";
		try
		{
			//value found -> print to which valie is iterator pointing
			std::cout << "Searching for 16" << std::endl;
			std::list<int>::iterator it = easyfind(l, 16);
			std::cout << "Element found: " << *it << std::endl;
			std::cout << "Insert an integer 42 before the element to which iterator is pointing" << std::endl;
			l.insert(it, 42); //The returned iterator remains valid
			std::cout << "Updated List has:";
			for (it = l.begin(); it != l.end(); ++it) {
				std::cout << " " << *it;
			}
			std::cout <<"\n";

			//value not found -> exeption error
			std::cout << "Searching for 0"<< std::endl;
			it = easyfind(l, 0);
			std::cout << "Element found: " << *it << std::endl;

		}
		catch (const std::runtime_error& e){
			std::cerr << e.what() <<std::endl;
		}
	}
	std::cout << "\n\n";
	{
		std::deque<int> dq;
		dq.push_back(100);
		dq.push_back(200);
		dq.push_back(300);
		dq.push_front(50);

		std::cout << "Deque Container has:";
		for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
			std::cout << " " << *it;
		std::cout << std::endl;

		try {
			std::cout << "Searching for 200" << std::endl;
			std::deque<int>::iterator it = easyfind(dq, 200);
			std::cout << "Element found: " << *it << std::endl;

			std::cout << "Searching for 999" << std::endl;
			it = easyfind(dq, 999);
			std::cout << "Element found: " << *it << std::endl;

		} catch (const std::runtime_error &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n\n";
	{
    std::string s = "hello_world";

    std::cout << "String has: " << s << std::endl;

    try {
        std::cout << "Searching for 'o' (ASCII 111)" << std::endl;
        std::string::iterator it = easyfind(s, 'o');  // works because char → int
        std::cout << "Found char: " << *it << std::endl;
		std::cout << "Inserting X before 'o'" << std::endl;
    	s.insert(it, '_'); //Iterator invalidation
		std::cout << "Updated string: " << s << std::endl;

        std::cout << "Searching for 'z'" << std::endl;
        it = easyfind(s, 'z');
        std::cout << "Found char: " << *it << std::endl;

    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}


}