/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:13:51 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/24 17:35:22 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook()
{
	this->current_index = 0;
	this->entry_count = 0;
}

PhoneBook::~PhoneBook() {}

Contact	PhoneBook::getContact(int index) const
{
	return (this->contacts[index]);
}

int	PhoneBook::getEntryCount() const
{
	return (this->entry_count);
}

void	PhoneBook::fillPhonebook(Contact contact)
{
	if (this->current_index > 7)
	{
		this->current_index = this->current_index%8;
	}
	this->contacts[this->current_index] = contact;
	this->current_index++;
	this->entry_count++;
	if (!std::cin.eof())
	{
		std::cout << MAGENTA << "Contact added" << RESET << std::endl;
	}
}
