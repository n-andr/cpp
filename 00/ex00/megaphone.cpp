/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:16:15 by nandreev          #+#    #+#             */
/*   Updated: 2024/11/07 23:46:30 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// using namespace std; 
// the using namespace <ns_name> and friend keywords are forbidden by the subject

int	main(int argc, char **argv) 
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j] != '\0';  j++)
			{
				std::cout << (char)std::toupper((unsigned char)argv[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
