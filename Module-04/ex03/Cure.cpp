/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:01:36 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/16 15:43:18 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "color.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(Cure const & source) : AMateria("cure")
{
	std::cout << "Cure Copy constructor called" << std::endl;
	*this = source;
}

Cure& Cure::operator=(Cure const & source)
{
	if (this != &source)
	{
		this->_type = source._type;
	}
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	Cure *new_cure = new Cure(*this);
	return (new_cure);
}

void Cure::use(ICharacter& target)
{
	std::cout<< BLUE << "* heals " << target.getName() << "'s wounds *" << RESET <<std::endl;
}
