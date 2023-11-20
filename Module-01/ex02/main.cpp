/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:33:23 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/31 14:25:59 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main ()
{
	std::string str =  "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable. " << "\033[35m" << &str << "\033[0m" << std::endl;
	std::cout << "The memory address held by stringPTR. " << "\033[35m" << stringPTR << "\033[0m" << std::endl;
	std::cout << "The memory address held by stringREF. " << "\033[35m" << &stringREF << "\033[0m" << std::endl;

	std::cout << "The value of the string variable. " << "\033[32m" << str << "\033[0m" << std::endl;
	std::cout << "The value pointed to by stringPTR. " << "\033[32m" << *stringPTR << "\033[0m" << std::endl;
	std::cout << "The value pointed to by stringREF. " << "\033[32m" << stringREF << "\033[0m" << std::endl;

	return 0;
}
