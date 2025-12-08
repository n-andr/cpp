#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
//# include <list> 
# include <cstddef>	// size_t
# include <stdexcept>
# include <string>
# include <climits>
# include <cstdlib>
# include <deque>
# include <iostream>


class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _deq;
	//int _size;
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void checkArgs(int argc, char** argv);
	void fillContainers(int argc, char** argv);
	void sortVector();
	std::vector<int> recurseVector(std::vector<int> vec);
	void insertPendIntoMainVector(std::vector<int> &mainChain, const std::vector<int> &pend);
	std::vector<int> buildJacobsthalVec(size_t n);

	template <typename T>
	void print(const T &container){
		for (std::size_t i = 0; i < container.size(); ++i)
			std::cout << " " << container[i];
		std::cout << std::endl;
	}
};

#endif