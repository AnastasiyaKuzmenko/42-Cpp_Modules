/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:05:06 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/24 17:36:11 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "utils.hpp"

void	displayMenu()
{
	std::cout << BOLDCYAN;
	std::cout << "*****************************************" << std::endl;
	std::cout << "*    Welcome to your new PhoneBook      *" << std::endl;
	std::cout << "*                                       *" << std::endl;
	std::cout << "*  ADD to save a new contact            *" << std::endl;
	std::cout << "*  SEARCH to display a specific contact *" << std::endl;
	std::cout << "*  EXIT to exit the Phonebook           *" << std::endl;
	std::cout << "*                                       *" << std::endl;
	std::cout << "*****************************************" << std::endl;

	std::cout << RESET;
}

int	main()
{
	Contact new_contact;
	PhoneBook phonebook;
	std::string input;

	displayMenu();
	while(1)
	{
		if (std::cin.eof())
			exit (0);
		std::getline(std::cin, input);
		if (input == "ADD" || input == "add")
		{	
			new_contact = addNewContact();
			phonebook.fillPhonebook(new_contact);
		}
		else if (input == "SEARCH" || input == "search")
		{
			showAllContacts(phonebook);
			searchContact(phonebook);
		}
		else if (input == "EXIT" || input == "exit")
		{
			std::cout << RED << "Exit" << RESET << std::endl;
			break;
		}
		else if (input != "")
		{
			std::cout << RED << "Invalid input" << RESET << std::endl;
		}
	}
	return 0;
}
