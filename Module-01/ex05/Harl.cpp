/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:30:51 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/27 15:22:24 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "This is an debug message" << std::endl;    
}

void	Harl::info(void)
{
	std::cout << "This is an info message" << std::endl;      
}

void	Harl::warning(void)
{
	std::cout << "This is an warning message" << std::endl;     
}

void	Harl::error(void)
{
	std::cout << "This is an error message" << std::endl;    
}

void	Harl::complain(std::string level)
{
	void (Harl::*funct_arr[4])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string posibble_input[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if(posibble_input[i].compare(level) == 0)
		{
			(this->*funct_arr[i])();
			break ;
		}
	}
}
