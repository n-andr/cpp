#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage example: " << argv[0] << " 9 8 7 6 5";
		return 1;
	}
	try
	{
		PmergeMe sorter;
		sorter.checkArgs(argc, argv);
		sorter.sortVector(argc, argv);
		sorter.sortDeque(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	

	return 0;
}