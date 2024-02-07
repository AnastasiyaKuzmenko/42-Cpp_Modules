/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:27:50 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/01/18 11:30:47 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\033[35m"<<  "Testing default constructor" << "\033[0m" << std::endl;
		Bureaucrat defaultBureaucrat;
		std::cout << defaultBureaucrat << std::endl;

	std::cout << "\033[35m"<<  "Testing int constructor" << "\033[0m" << std::endl;
		Bureaucrat intBureaucrat(5);
		std::cout << intBureaucrat << std::endl;
			
	std::cout << "\033[35m"<<  "Testing string constructor" << "\033[0m" << std::endl;
		Bureaucrat strBureaucrat("John");
		std::cout << strBureaucrat << std::endl;

	std::cout << "\033[35m"<<  "Testing constructor with empty name" << "\033[0m" << std::endl;
		Bureaucrat emptyName("", 12);
		std::cout << emptyName << std::endl;

	std::cout << "\033[35m"<<  "Testing the increase function exception" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat a("Alex", 1);
		a.incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& obj)
	{
		std::cout << obj.what() << std::endl;
	}

	std::cout << "\033[35m" << "Testing the decrese exception"<< "\033[0m" << std::endl;
	try
	{
		Bureaucrat a("Ivan", 150);
		a.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooLowException& obj)
	{
		std::cout << obj.what() << std::endl;
	}

	std::cout << "\033[35m" << "Testing good value at construction"<< "\033[0m" << std::endl;
	try
	{
		Bureaucrat a("Dima", 120);
	}
	catch(const Bureaucrat::GradeTooLowException& obj)
	{
		std::cout << obj.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& obj)
	{
		std::cout << obj.what() << std::endl;
	}

	std::cout << "\033[35m" << "Testing << operator overload"<< "\033[0m" << std::endl;
	try
	{
		Bureaucrat a("Denis", 100);
		std::cout << a << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& obj)
	{
		std::cout << obj.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& obj)
	{
		std::cout << obj.what() << std::endl;
	}

	return 0;
}
