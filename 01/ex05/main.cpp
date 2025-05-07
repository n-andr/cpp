/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:08:13 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/07 02:19:17 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(){

	Harl harlObj;
	
	harlObj.complain("DEBUG");
	harlObj.complain("INFO");
	harlObj.complain("WARNING");
	harlObj.complain("ERROR");

	harlObj.complain("");
	
	return 0;
}