/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:52:01 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/15 11:55:11 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer: default constructor started" << std::endl;
}

Serializer::Serializer(const Serializer &source)
{
	std::cout << "Serializer: copy constructor called" << std::endl;
	*this = source;
}

Serializer &Serializer::operator=(const Serializer &source)
{
	std::cout << "Serializer: copy assignment operator called" << std::endl;
	(void) source;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer: destructor called" << std::endl;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}
