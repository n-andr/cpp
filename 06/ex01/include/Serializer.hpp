/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:48:40 by nandreev          #+#    #+#             */
/*   Updated: 2025/11/05 12:28:18 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERIALIZER_HPP
# define	SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h> // for uintptr_t

class Serializer
{
private: 
	Serializer();  // private constructors to prevent initialization 
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
    ~Serializer();
	
public:

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif