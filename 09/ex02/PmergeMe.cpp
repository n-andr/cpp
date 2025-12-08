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

    static int depth = 0; 	// static = shared between all recursion levels (for indentation)

	//delete
	std::string indent(depth * 2, ' ');

    // ---- Debug: entering ----
    std::cout << indent << "recurseVector(depth=" << depth << ") called with input:";
    print(input);

	//end delete
	const size_t n = input.size();

	if (n <= 1){std::cout << indent << "Base case (n <= 1), returning:";
        return input;}
	std::vector<int> larger;
	std::vector<int> pending;

	//std::cout << indent << "Pairing elements:" << std::endl;
	for (size_t i = 0; i + 1 < n; i += 2) {
		int a = input[i];
		int b = input[i + 1];
        std::cout << indent << "  Pair (" << a << ", " << b << ") -> ";

		if (a < b) {
			pending.push_back(a);
			larger.push_back(b);
			            std::cout << "pending += " << a << ", larger += " << b << std::endl;

		} else {
			pending.push_back(b);
			larger.push_back(a);
			            std::cout << "pending += " << b << ", larger += " << a << std::endl;

		}
	}

	if (n % 2 == 1)
	{
		int leftover = input[n - 1];
        pending.push_back(leftover);
        std::cout << indent << "Odd leftover -> pending += " << leftover << std::endl;
	}
	
	 //std::cout << indent << "Recurse on larger..." << std::endl;
    ++depth;
	std::vector<int> mainChain = recurseVector(larger);
    --depth;

	indent = std::string(depth * 2, ' '); // recompute indent for this level

    std::cout << indent << "Back from recursion at depth=" << depth
              << ", mainChain now:";
    print(mainChain);
    // -----------------------------------------
    // 3. Insert pend elements into mainChain
    //    (Jacobsthal + binary insertion)
    // -----------------------------------------
    insertPendIntoMainVector(mainChain, pending);
	std::cout << indent << "Returning from depth=" << depth << " with chain:";
    print(mainChain);

    return mainChain;
}

void PmergeMe::insertPendIntoMainVector(std::vector<int> &mainChain,
                                  const std::vector<int> &pend)
{
    if (pend.empty())
        return;

	for (size_t i = 0; i < pend.size(); ++i) {
        int value = pend[i];

		std::cout << "Insert pend[" << i << "] = " << value << std::endl;

        // ---- binary search ----
        size_t left = 0;
        size_t right = mainChain.size();

        while (left < right) {
            size_t mid = (left + right) / 2;
			 std::cout << "  BS: left=" << left
                      << " mid=" << mid
                      << " right=" << right
                      << " | comparing " << value
                      << " with " << mainChain[mid]
                      << std::endl;
            if (value < mainChain[mid])
                right = mid;
            else
                left = mid + 1;
        }
		std::cout << "  -> insert at position " << left << std::endl;

        // ---- insert into vector ----
        mainChain.insert(mainChain.begin() + left, value);

		std::cout << "  mainChain: ";
        for (size_t j = 0; j < mainChain.size(); ++j)
            std::cout << mainChain[j] << " ";
        std::cout << std::endl << std::endl;
	}
}



// std::vector<int> PmergeMe::buildJacobsthalVec(size_t n){

// 	std::vector<int> seq;

// 	// Jacobsthal numbers: J(1) = 1, J(2) = 3
//     size_t j_prev = 1;
//     size_t j_curr = 3;

//     // Add J(1)
//     if (j_prev <= n)
//         order.push_back(j_prev - 1);

//     // Add J(2)
//     if (j_curr <= n)
//         order.push_back(j_curr - 1);

//     // Add higher Jacobsthal indices
//     while (true) {
//         size_t j_next = j_curr + 2 * j_prev;

//         if (j_next > n)
//             break;

//         order.push_back(j_next - 1);

//         j_prev = j_curr;
//         j_curr = j_next;
//     }
// 	return seq;
// }
