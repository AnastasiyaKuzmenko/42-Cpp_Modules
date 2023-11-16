/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:41:18 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/24 16:29:29 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string	Contact::getFirstName() const
{
	return (this->first_name);
}

std::string	Contact::getLastName() const
{
	return (this->last_name);
}

std::string	Contact::getNickname() const
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (this->phone_number);
}

std::string	Contact::getDarkestSecret() const
{
	return (this->darkest_secret);
}

void	Contact::setFirstName(std::string input_first_name)
{
	this->first_name = input_first_name;
}

void	Contact::setLastName(std::string input_last_name)
{
	this->last_name = input_last_name;
}

void	Contact::setNickname(std::string input_nickname)
{
	this->nickname = input_nickname;
}
	
void	Contact::setPhoneNumber(std::string input_phone_number)
{
	this->phone_number = input_phone_number;
}

void	Contact::setDarkestSecret(std::string input_darkest_secret)
{
	this->darkest_secret = input_darkest_secret;
}
