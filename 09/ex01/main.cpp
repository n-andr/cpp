#include "RNP.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage example:  ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\" ";
		return 1;
	}
	try
	{
		double result = RPN::calculate(argv[1]);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	

	return 0;
}