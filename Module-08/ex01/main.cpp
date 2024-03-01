/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:29:14 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/27 14:20:45 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <list>

int main()
{
	std::cout << "\033[35m" << "Test from subject " << "\033[0m" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << std::endl;
	std::cout << "\033[35m" << "Test: NotEnoughNumbersException()" << "\033[0m" << std::endl;
	Span sp1 = Span(2);
	sp1.addNumber(1);
	try
	{
		std::cout << sp1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << sp1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "\033[35m" << "Test: FullStorageException()" << "\033[0m" << std::endl;
	Span sp2 = Span(5);
	try
	{
		sp2.addNumber(10);
		sp2.addNumber(20);
		sp2.addNumber(30);
		sp2.addNumber(40);
		sp2.addNumber(50);
		sp2.addNumber(60);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[35m" << "Test: addNumber(start, end)" << "\033[0m" << std::endl;
	try {
		Span sp3(10);
		std::vector<int> numbers;
		for (int i = 0; i < 10; i++)
		{
			numbers.push_back(i*10);
		}
		sp3.addNumber(numbers.begin(), numbers.end());
		std::cout << "Numbers in Span:" << std::endl;
		for (std::vector<int>::iterator it = sp3.getData().begin(); it != sp3.getData().end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	} 
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "\033[35m" << "Test: copy constructor" << "\033[0m" << std::endl;
	try
	{
		Span sp4 = Span(3);
		sp4.addNumber(1);
		sp4.addNumber(2);
		sp4.addNumber(3);

		Span sp5 = Span(sp4);
		std::cout << "sp4:" << std::endl;
		for (std::vector<int>::iterator it = sp4.getData().begin(); it != sp4.getData().end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;	
		std::cout << "sp5:" << std::endl;
		for (std::vector<int>::iterator it = sp5.getData().begin(); it != sp5.getData().end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl;
	std::cout << "\033[35m" << "Test: copy assignment operator" << "\033[0m" << std::endl;
	try
	{
		Span sp6 = Span(3);
		sp6.addNumber(1);
		sp6.addNumber(2);
		sp6.addNumber(3);

		Span sp7 = sp6;
		std::cout << "sp6:" << std::endl;
		for (std::vector<int>::iterator it = sp6.getData().begin(); it != sp6.getData().end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;	
		std::cout << "sp7:" << std::endl;
		for (std::vector<int>::iterator it = sp7.getData().begin(); it != sp7.getData().end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
