/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:56:27 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/19 15:39:29 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Default constructor called" << std::endl;
	this->_type = "";
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria String constructor called" << std::endl;
	this->_type = type;
}

AMateria::AMateria(const AMateria &source)
{
	std::cout << "AMateria Copy constructor called" << std::endl;
	*this = source;
}

AMateria &AMateria::operator=(const AMateria &source)
{
	if (this != &source)
	{
		this->_type = source._type;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}
