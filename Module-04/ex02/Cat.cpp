/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:41:57 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/19 13:58:37 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &source) : Animal()
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = source;
}

Cat &Cat::operator=(const Cat &source)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
		*this->_brain = *source._brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const
{
	std::cout << "Cat make sound. Miaw Miaw" << std::endl;
}

Brain *Cat::getBrain(void)
{
	return(this->_brain);
}
