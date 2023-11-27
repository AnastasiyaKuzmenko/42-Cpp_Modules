/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:41:32 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/16 12:11:07 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &source)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = source;
}

Animal &Animal::operator=(const Animal &source)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

