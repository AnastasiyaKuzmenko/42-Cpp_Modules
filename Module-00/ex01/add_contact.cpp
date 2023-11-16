/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:20:24 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/24 17:36:46 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "utils.hpp"

Contact	addNewContact()
{
	std::string input = "";
	Contact new_contact;

	while (input == "" && !std::cin.eof())
	{
		std::cout << GREEN << "first_name:" << RESET << std::endl;
		std::getline (std::cin, input);
		if (input != "")
			new_contact.setFirstName(input);
	}
	input = "";
	while (input == "" && !std::cin.eof())
	{
		std::cout << GREEN << "last_name:" << RESET << std::endl;
		std::getline (std::cin, input);
		if (input != "")
			new_contact.setLastName(input);
	}
	input = "";
	while (input == "" && !std::cin.eof())
	{
		std::cout << GREEN << "nickname:" << RESET << std::endl;
		std::getline (std::cin, input);
		if (input != "")
			new_contact.setNickname(input);
	}
	input = "";
	while (input == "" && !std::cin.eof())
	{
		std::cout << GREEN << "phone_number:" << RESET << std::endl;
		std::getline (std::cin, input);
		while (isNotDigit(input))
		{
			std::cout << RED << "Invalid phone number" << RESET << std::endl;
			std::cout << GREEN << "phone_number:" << RESET << std::endl;
			std::getline (std::cin, input);
		}
		if (input != "")
		new_contact.setPhoneNumber(input);
	}
	input = "";
	while (input == "" && !std::cin.eof())
	{
		std::cout << GREEN << "darkest_secret:" << RESET << std::endl;
		std::getline (std::cin, input);
		if (input != "")
			new_contact.setDarkestSecret(input);
	}
	return new_contact;
}
