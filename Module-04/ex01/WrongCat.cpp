/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:42:57 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/13 13:07:09 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &source) : WrongAnimal()
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = source;
}

WrongCat &WrongCat::operator=(const WrongCat &source)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat make sound. Miaw Miaw" << std::endl;
}
