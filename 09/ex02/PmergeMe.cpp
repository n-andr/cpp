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




/*----------------------------           START            --------------------------------*/
/*----------------------------sort using vector container --------------------------------*/

void PmergeMe::sortVector(int argc, char **argv){

	std::vector<int> original;
	fillContainer(original, argc, argv); //save original input
	
	// time start
    clock_t start = clock();
	fillContainer(_vec, argc, argv);
	if (_vec.size() <= 1) return;
    _vec = recurseVector(_vec);
	//finish time here
	clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Before: ";
    print(original);

    std::cout << "After:  ";
    print(_vec);

    std::cout << "Time to process a range of "
              << _vec.size()
              << " elements with std::vector : "
              << elapsed << " us\n";
}


std::vector<int> PmergeMe::recurseVector(std::vector<int> input){

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
	pending = alignPendWithMain(mainChain, pairs);

	if (n % 2 == 1)
	{
		int leftover = input[n - 1];
        pending.push_back(leftover);
	}
	
    insertPendIntoMainVector(mainChain, pending, pairs);

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
	std::vector<size_t> j_seq = buildJacobsthalVec(pend.size());
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



std::vector<size_t> PmergeMe::buildJacobsthalVec(size_t n){

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

std::vector<size_t> PmergeMe::completeInsertionOrder( std::vector<size_t> &boundaries, size_t n)
{
    std::vector<size_t> order;
    
    // 1. Build boundary list usinf J-numbers
    // Add final boundary at n

    if (boundaries.empty() || boundaries.back() != n)
        boundaries.push_back(n);

    order.push_back(0);

    for (size_t b = 1; b < boundaries.size(); ++b)
    {
        size_t prev = boundaries[b-1];
        size_t curr = boundaries[b];
        for (size_t pos = curr; pos > prev; --pos)
        {
            // Convert to 0-based index
            size_t index0 = pos - 1;
            if (index0 < n)
                order.push_back(index0);
        }
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

/*----------------------------            END              --------------------------------*/
/*---------------------------- sort using vector container --------------------------------*/



/*----------------------------           START            --------------------------------*/
/*----------------------------sort using deque container --------------------------------*/

void PmergeMe::sortDeque(int argc, char **argv){


	// time start
    clock_t start = clock();
	fillContainer(_deq, argc, argv);
	if (_deq.size() <= 1) return;
    _deq = recurseDeque(_deq);
	//finish time here
	clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of "
              << _deq.size()
              << " elements with std::deque : "
              << elapsed << " us\n";
}


std::deque<int> PmergeMe::recurseDeque(std::deque<int> input){

	const size_t n = input.size();

	if (n <= 1){
        return input;}
	std::deque<Pair> pairs;
	std::deque<int> larger;
	std::deque<int> pending;

	for (size_t i = 0; i + 1 < n; i += 2) {
		int a = input[i];
		int b = input[i + 1];

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
	
	std::deque<int> mainChain = recurseDeque(larger);
	pending = alignPendWithMainDeque(mainChain, pairs);

	if (n % 2 == 1)
	{
		int leftover = input[n - 1];
        pending.push_back(leftover);
	}
	
    insertPendIntoMainDeque(mainChain, pending, pairs);

    return mainChain;
}

std::deque<int> PmergeMe::alignPendWithMainDeque(const std::deque<int> &mainChain, const std::deque<Pair> &pairs)
{
    std::deque<int> alignedPend;

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


void PmergeMe::insertPendIntoMainDeque(std::deque<int> &mainChain, const std::deque<int> &pend, std::deque<Pair> &pairs)
{
    if (pend.empty())
        return;

	// Build Jacobsthal numbers
	std::deque<size_t> j_seq = buildJacobsthalDeque(pend.size());
	std::deque<size_t> order = completeInsertionOrderD(j_seq, pend.size());

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
		binaryInsertD(mainChain, value, rightPos);
	}
}



std::deque<size_t> PmergeMe::buildJacobsthalDeque(size_t n){

	std::deque<size_t> j_seq;

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

std::deque<size_t> PmergeMe::completeInsertionOrderD(std::deque<size_t> &boundaries, size_t n)
{
    std::deque<size_t> order;

    // Add final boundary at n
    if (boundaries.empty() || boundaries.back() != n)
        boundaries.push_back(n);

    order.push_back(0);

    for (size_t b = 1; b < boundaries.size(); ++b)
    {
        size_t prev = boundaries[b-1];
        size_t curr = boundaries[b];

        for (size_t pos = curr; pos > prev; --pos)
        {
            size_t index0 = pos - 1;
            if (index0 < n)
                order.push_back(index0);
        }
    }

    return order;
}


void PmergeMe::binaryInsertD(std::deque<int> &mainChain, int value, int rightPos)
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

/*----------------------------            END              --------------------------------*/
/*---------------------------- sort using deque container --------------------------------*/





