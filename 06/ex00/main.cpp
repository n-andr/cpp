/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:00:57 by nandreev          #+#    #+#             */
/*   Updated: 2025/08/03 19:03:42 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[]){
	if (argc != 2) {
		std::cout << "Usage: ./converter <literal>" << std::endl;
        return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}