#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		//sunject test
		std::cout << "Test : subject test" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
				//sunject test
		std::cout << "Test : subject test (replase with list and compare)" << std::endl;
		std::list<int> l;
		l.push_back(5);
		l.push_back(17);
		std::cout << l.back() << std::endl;
		l.pop_back();
		std::cout << l.size() << std::endl;
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		//[...]
		l.push_back(0);
		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> l2(l);

	}
	std::cout << std::endl;
    {
		std::cout << "Test : iterator stability" << std::endl;
        MutantStack<int> ms;
        ms.push(10);
        ms.push(20);
        ms.push(30);

        MutantStack<int>::iterator it = ms.begin();
		it++;
        std::cout << "Iterator initially points to: " << *it << std::endl;

        ms.push(40);
        std::cout << "After push(40), iterator still points to: " << *it << std::endl;

        ms.pop();
        std::cout << "After pop(), iterator still points to: " << *it << std::endl;
    }
	std::cout << std::endl;
    {
		std::cout << "Test : modify element using iterator" << std::endl;
        MutantStack<int> ms;
        ms.push(10);
        ms.push(20);
        ms.push(30);

		//print here

        MutantStack<int>::iterator it = ms.begin();
		it++;
        std::cout << "Iterator initially points to: " << *it << std::endl;

        ms.push(40);
		ms.push(000000);
        ms.pop();

		*it = 9999;
		std::cout << "After modification Iterator points to: " << *it << std::endl;
		std::cout << "Stack after modification: ";
    	for (MutantStack<int>::iterator pit = ms.begin(); pit != ms.end(); ++pit)
        std::cout << *pit << " ";
    }


	return 0;
}