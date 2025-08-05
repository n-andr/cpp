/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:48:52 by nandreev          #+#    #+#             */
/*   Updated: 2025/08/05 23:43:10 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Serializer.hpp"

// Converts Data pointers to uintptr_t.
uintptr_t	Serializer::serialize(Data* data){
	return (reinterpret_cast<uintptr_t>(data));
}

// Converts uintptr_t back to Data pointers.
Data*	Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}