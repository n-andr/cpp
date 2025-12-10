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
	struct Pair {
        int small;
        int large;
    };
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void checkArgs(int argc, char** argv);

	//sort using vector container
	void sortVector(int argc, char **argv);
	std::vector<int> recurseVector(std::vector<int> vec);
	void insertPendIntoMainVector(std::vector<int> &mainChain, const std::vector<int> &pend, std::vector<Pair> &pairs);
	std::vector<size_t> buildJacobsthalVec(size_t n);
	void binaryInsert(std::vector<int> &mainChain, int value, int rightPos);
	std::vector<int> alignPendWithMain(const std::vector<int> &mainChain, const std::vector<Pair> &pairs);
	std::vector<size_t> completeInsertionOrder( std::vector<size_t> &jac, size_t n);

	// sort using deque container
	void sortDeque(int argc, char **argv);
	std::deque<int> recurseDeque(std::deque<int> input);
	std::deque<int> alignPendWithMainDeque(const std::deque<int> &mainChain, const std::deque<Pair> &pairs);
	void insertPendIntoMainDeque(std::deque<int> &mainChain, const std::deque<int> &pend, std::deque<Pair> &pairs);
	std::deque<size_t> buildJacobsthalDeque(size_t n);
	std::deque<size_t> completeInsertionOrderD(std::deque<size_t> &j_seq, size_t n);
	void binaryInsertD(std::deque<int> &mainChain, int value, int rightPos);

	// utils
	template <typename T>
	void print(const T &container){
		for (std::size_t i = 0; i < container.size(); ++i)
			std::cout << " " << container[i];
		std::cout << std::endl;
	}
	template <typename Container>
	void fillContainer(Container &c, int argc, char **argv)
	{
		for (int i = 1; i < argc; ++i) {
			c.push_back(std::atoi(argv[i]));
		}
	}
};


#endif