/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:27:50 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/01/29 16:20:28 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\033[1m\033[32m"<<  "test with ValidForm" << "\033[0m" << std::endl;
	try
	{
		std::cout << "\033[35m"<<  "Create Bureaucrat" << "\033[0m" << std::endl;
		Bureaucrat Alex("Alex", 10);
		std::cout << Alex << std::endl;
		std::cout << "\033[35m"<<  "Create ValidForm" << "\033[0m" << std::endl;
		Form firstForm("ValidForm", 10, 10);
		std::cout << firstForm;
		std::cout << "\033[35m"<<  "Sign ValidForm" << "\033[0m" << std::endl;
		Alex.signForm(firstForm);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout <<"\033[1m\033[32m"<<  "test with NotValidForm" << "\033[0m" << std::endl;
	std::cout << "\033[35m"<<  "Create Bureaucrat" << "\033[0m" << std::endl;
	Bureaucrat Jonh("Jonh", 120);
	std::cout << Jonh << std::endl;
	std::cout << "\033[35m"<<  "Create NotValidForm" << "\033[0m" << std::endl;
	Form secondForm("NotValidForm", 1, 1);
	std::cout << secondForm;
	try
	{
		std::cout << "\033[35m"<<  "Sign NotValidForm" << "\033[0m" << std::endl;
		Jonh.signForm(secondForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
