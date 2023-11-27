/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:42:14 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/13 13:06:16 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &source) : Animal()
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = source;
}

Dog &Dog::operator=(const Dog &source)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog make sound. Woof Woof" << std::endl;
}
