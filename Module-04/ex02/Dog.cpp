/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:42:14 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/19 16:50:26 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &source) : Animal()
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = source;
}

Dog &Dog::operator=(const Dog &source)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
		*this->_brain = *source._brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "Dog make sound. Woof Woof" << std::endl;
}

Brain *Dog::getBrain(void)
{
	return(this->_brain);
}
