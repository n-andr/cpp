#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
//# include <list> 
# include <cstddef>	// size_t

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
public:
	static void checkArgs(int argc, char** argv);
	static void sortVector();
	
};

