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
		sorter.fillContainers(argc, argv);
		sorter.sortVector();

		sorter.print(sorter.completeInsertionOrder(sorter.buildJacobsthalIndicesVec(100), 100));
		
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	

	return 0;
}