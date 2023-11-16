/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_contact.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:33:13 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/26 14:26:13 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "utils.hpp"

std::string	trimString(std::string str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
	return str;
}

void	showAllContacts(PhoneBook phonebook)
{
	std::cout << "|--------------Contact Display--------------|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|" << std::setw(10) << std::left << "INDEX";
	std::cout << "|" << std::setw(10) << std::left << "FIRST NAME";
	std::cout << "|" << std::setw(10) << std::left << "LAST NAME";
	std::cout << "|" << std::setw(10) << std::left << "NICKNAME" << "|";
	std::cout << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

	for (int id = 0; id < 8; id++)
	{
		if (phonebook.getContact(id).getFirstName()[0] == '\0')
			break;
		std::cout<<"|" << std::setw(10) << std::right<<id;
		std::cout<<"|" << std::setw(10) << std::right<<trimString(phonebook.getContact(id).getFirstName());
		std::cout<<"|" << std::setw(10) << std::right<<trimString(phonebook.getContact(id).getLastName());
		std::cout<<"|" << std::setw(10) << std::right<<trimString(phonebook.getContact(id).getNickname()) << "|";
		std::cout << std::endl;
	}
}

void	showOneContact(PhoneBook phonebook, int index)
{
	std::cout << BLUE << "\nFirst name: " << RESET << phonebook.getContact(index).getFirstName() << std::endl;
	std::cout << BLUE << "Last name: " << RESET << phonebook.getContact(index).getLastName() << std::endl;
	std::cout << BLUE << "Nickname name: " << RESET << phonebook.getContact(index).getNickname() << std::endl;
	std::cout << BLUE << "Phone number: " << RESET << phonebook.getContact(index).getPhoneNumber() << std::endl;
	std::cout << BLUE << "Darkest secret: " << RESET << phonebook.getContact(index).getDarkestSecret() << std::endl;
}

int	isNotDigit(std::string number)
{
	int i = 0;

	while (number[i])
	{
		if (!(number[i] >= 48 && number[i] <= 57))
			return 1;
		i++;
	}
	return 0;
}

void	searchContact(PhoneBook phonebook)
{
	std::string input = "";
	int index;

	if (phonebook.getEntryCount() == 0)
	{
		std::cout << std::setw(40) << std::right << "*Phonebook is empty*" << std::endl;
	}
	else
	{
		while (1)
		{
			std::cout << MAGENTA << "Write the index of the number you want to search" << RESET << std::endl;
			std::getline(std::cin, input);
			if (input == "END" || input == "end" || std::cin.eof())
			{
				break;
			}
			else if (input == "" || isNotDigit(input))
			{
				std::cout << RED << "Invalid index" << RESET << std::endl;
				continue;
			}
			index = std::stoi(input);
			if (index < 0 || index > 7)
			{
				std::cout << RED << "Invalid index" << RESET << std::endl;
			}
			else if (phonebook.getContact(index).getFirstName() == "")
			{
				std::cout << RED << "Choose another index" << RESET <<std::endl;
			}
			else
			{
				showOneContact(phonebook, index);
				break;
			}
		}
	}
}
