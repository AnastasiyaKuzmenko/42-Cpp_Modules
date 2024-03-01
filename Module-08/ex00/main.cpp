/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:08:24 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/27 11:50:41 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int	main()
{
	std::cout << "\033[35m" << " test1 " << "\033[0m" << std::endl;
	std::vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i*i);
	}
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << std::endl;
	}
	try
	{
		std::vector<int>::iterator v1_iterator = easyfind(v1, 9);
		std::cout << *v1_iterator << std::endl;
	}
	catch (NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[35m" << " test2 " << "\033[0m" << std::endl;
	std::list<int> l1;
	for (int i = 0; i < 10; i++)
	{
		l1.push_back(i*i);
	}
	try
	{
		std::list<int>::iterator l1_iterator = easyfind(l1, 15);
		std::cout << *l1_iterator << std::endl;
	}
	catch (NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
