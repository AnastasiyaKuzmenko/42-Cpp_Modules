/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:10:00 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/03/05 13:11:20 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	RPN	rpn;

	if (argc != 2)
	{
		std::cout << "Error: invalid input" << std::endl;
		return 1;
	}
	try
	{
		rpn.reversePolishNotation(argv[1]);
		std::cout << rpn << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
