/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:41:57 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/13 13:05:48 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &source) : Animal()
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = source;
}

Cat &Cat::operator=(const Cat &source)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat make sound. Miaw Miaw" << std::endl;
}
