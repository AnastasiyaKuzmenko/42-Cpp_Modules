/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:01:58 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/16 15:42:52 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "color.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(Ice const & source) : AMateria("ice")
{
	std::cout << "Ice Copy constructor called" << std::endl;
	*this = source;
}

Ice& Ice::operator=(Ice const & source)
{
	if (this != &source)
	{
		this->_type = source._type;
	}
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	Ice	*new_ice = new Ice(*this);
	return (new_ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() <<  " *" << RESET <<std::endl;
}
