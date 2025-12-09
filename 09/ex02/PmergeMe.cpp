#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vec(), _deq(){}
PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq){}
PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    } return *this;
}
PmergeMe::~PmergeMe(){}


void PmergeMe::checkArgs(int argc, char** argv){
	for (int i = 1; i < argc; ++i){
		std::string argument(argv[i]);

		if (argument.empty()) throw std::runtime_error("Error: empty argument");
		
		for (size_t j = 0; j < argument.size(); ++j){
			if (!std::isdigit(argument[j]))
				throw std::runtime_error("Error: invalid character in input");
		}
		long val = std::strtol(argument.c_str(), NULL, 10);
        if (val < 0 || val > INT_MAX)
            throw std::runtime_error("Error: integer out of range");

		//duplicates are allowed
	}

}

void PmergeMe::fillContainers(int argc, char** argv) {
	// _size = argc - 1;
    for (int i = 1; i < argc; ++i) {
        int n = std::atoi(argv[i]);
        _vec.push_back(n);
        _deq.push_back(n);
    }
}


void PmergeMe::sortVector(){

	if (_vec.size() <= 1) return;

	// std::vector<int> mainChain;
    // std::vector<int> pend;


    //pairAndRecurse(_vec, mainChain, pend);

    // later: insert pend elements using Jacobsthal sequence

	//add timestamp here
    _vec = recurseVector(_vec);
	std::cout << "RESULT: \n";
	print(_vec);

}

std::vector<int> PmergeMe::recurseVector(std::vector<int> input){

    // ---- Debug: entering ----
    std::cout << "recurseVector called with input:";
    print(input);

	//end delete
	const size_t n = input.size();

	if (n <= 1){
        return input;}
	std::vector<Pair> pairs;
	std::vector<int> larger;
	std::vector<int> pending;

	//std::cout << indent << "Pairing elements:" << std::endl;
	for (size_t i = 0; i + 1 < n; i += 2) {
		int a = input[i];
		int b = input[i + 1];
        std::cout << "  Pair (" << a << ", " << b << ") -> ";

		Pair p;
        if (a < b) {
            p.small = a;
            p.large = b;
        } else {
            p.small = b;
            p.large = a;
        }

        pairs.push_back(p);
        larger.push_back(p.large);
        pending.push_back(p.small);
	}
	
	std::vector<int> mainChain = recurseVector(larger);
	std::cout << "Back from recursion, mainChain now:";
    print(mainChain);
	pending = alignPendWithMain(mainChain, pairs);

	if (n % 2 == 1)
	{
		int leftover = input[n - 1];
        pending.push_back(leftover);
        std::cout << "Odd leftover -> pending += " << leftover << std::endl;
	}
	
    insertPendIntoMainVector(mainChain, pending, pairs);
	std::cout << "Returning with chain:";
    print(mainChain);

    return mainChain;
}

std::vector<int> PmergeMe::alignPendWithMain(const std::vector<int> &mainChain, const std::vector<Pair> &pairs)
{
    std::vector<int> alignedPend;

    for (size_t i = 0; i < mainChain.size(); ++i) {
        int l = mainChain[i];

        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].large == l) {
                alignedPend.push_back(pairs[j].small);
                break;
            }
        }
    }

    return alignedPend;
}


void PmergeMe::insertPendIntoMainVector(std::vector<int> &mainChain, const std::vector<int> &pend, std::vector<Pair> &pairs)
{
    if (pend.empty())
        return;

	// Build Jacobsthal numbers
	std::vector<size_t> j_seq = buildJacobsthalIndicesVec(pend.size());
	std::vector<size_t> order = completeInsertionOrder(j_seq, pend.size());

	for (size_t i = 0; i < pend.size(); ++i) {
		size_t pendIndex = order[i];
        int value = pend[pendIndex]; // the value we need to insert

		 // ------- find its matching large -------
        int large = -1;
        for (size_t k = 0; k < pairs.size(); ++k) {
            if (pairs[k].small == value) {
                large = pairs[k].large;
                break;
            }
        }

        // ------- find insertion window -------
        int rightPos = -1;
        if (large != -1) {
            for (size_t pos = 0; pos < mainChain.size(); ++pos) {
                if (mainChain[pos] == large) {
                    rightPos = pos;
                    break;
                }
            }
        }
        // ---- binary search ----
		binaryInsert(mainChain, value, rightPos);
	}
}



std::vector<size_t> PmergeMe::buildJacobsthalIndicesVec(size_t n){

	std::vector<size_t> j_seq;

	// Jacobsthal numbers: 
	// 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, …

    size_t j_prev = 0;
    size_t j_curr = 1;

	size_t j_next = j_curr + 2 * j_prev;
    while (j_next <= n) {
		j_seq.push_back(j_next);

		j_prev = j_curr;
		j_curr = j_next;
		j_next = j_curr + 2 * j_prev;
	}
	return j_seq;
}

std::vector<size_t> PmergeMe::completeInsertionOrder(const std::vector<size_t> &j_seq, size_t n)
{
    std::vector<size_t> order;
    std::vector<bool> used(n, false);

	// indices, based on Jacobsthal numbers are:
	// 0 2 4 10 20 42 84 170 340 682 1364 2730 5460 10922 ...

    for (size_t i = 0; i < j_seq.size(); ++i) {
        size_t idx = j_seq[i] - 1;      // convert “1 → 0”, “3 → 2”
        if (idx < n) {
            order.push_back(idx);
            used[idx] = true;
        }
    }

    // Add missing indices
	// 1 3 5 6 7 8 9 ...
    for (size_t i = 0; i < n; ++i) {
        if (!used[i])
            order.push_back(i);
    }

    return order;
}


void PmergeMe::binaryInsert(std::vector<int> &mainChain, int value, int rightPos)
{
    size_t left = 0;
    size_t right = mainChain.size();
	if (rightPos != -1) right = rightPos;

    while (left < right) {
        size_t mid = (left + right) / 2;

        if (value < mainChain[mid])
            right = mid;
        else
            left = mid + 1;
    }

    mainChain.insert(mainChain.begin() + left, value);
}
