/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:18:22 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/13 13:46:25 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &source)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = source;
}

Brain &Brain::operator=(const Brain &source)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	for (int index = 0; index < 100; index++)
	{
		this->_ideas[index] = source._ideas[index];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

std::string Brain::getIdea(int index)
{
	return (this->_ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index > 99)
	{
		std::cout << "My brain is too small" << std::endl;
	}
	else
	{
		this->_ideas[index] = idea;
	}
}
