/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:20:11 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/15 11:53:22 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <chrono>

Base * generate()
{
	Base *base;

	srand(time(NULL));
	int	randomValue = std::rand() % 3;
	switch (randomValue)
	{
		case 0:
		{
			base = new A();
			break;
		}
		case 1:
		{
			base = new B();
			break;   
		}
		case 2:
		{
			base = new C();
			break;   
		}
	}
	return base;
}

void	identify(Base *p)
{
	if(p == nullptr)
		return ;
	if(dynamic_cast< A* >(p))
		std::cout << "* A" << std::endl;
	else if(dynamic_cast< B* >(p))
		std::cout << "* B" << std::endl;
	else if(dynamic_cast< C* >(p))
		std::cout << "* C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast< A& >(p);
		std::cout << "& A" << std::endl;
	}
	catch(std::exception &e) {}
	try
	{
		(void)dynamic_cast< B& >(p);
		std::cout << "& B" << std::endl;
	}
	catch(std::exception &e) {}
	try
	{
		(void)dynamic_cast< C& >(p);
		std::cout << "& C" << std::endl;
	}
	catch(std::exception &e) {}
}


int	main()
{
	std::cout << "\033[35m" << " test " << "\033[0m" << std::endl;
	Base *ptr = generate();
	Base &ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;

	return 0;
}
