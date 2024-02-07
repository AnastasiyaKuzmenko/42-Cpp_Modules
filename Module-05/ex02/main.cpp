/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:27:50 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/06 14:45:48 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		std::cout << "\033[35m"<<  "Create Bureaucrat" << "\033[0m" << std::endl;
		Bureaucrat Jonh = Bureaucrat("Jonh", 25);

		std::cout << "\033[35m"<<  "Create Form" << "\033[0m" << std::endl;

		AForm* form1 = new PresidentialPardonForm("Home");
		AForm* form2 = new RobotomyRequestForm("Home");
		AForm* form3 = new ShrubberyCreationForm("Home");

		std::cout << "\033[35m"<< "Form's information" << "\033[0m" << std::endl;
		std::cout << *form1;
		std::cout << *form2;
		std::cout << *form3;

		std::cout << "\033[35m"<< "Sign Form" << "\033[0m" << std::endl;
		Jonh.signForm(*form1);
	//	Jonh.signForm(*form2);
	//	Jonh.signForm(*form3);

		std::cout << "\033[35m"<< "Exec Form" << "\033[0m" << std::endl;
		Jonh.executeForm(*form1);
	//	Jonh.executeForm(*form2);
	//	Jonh.executeForm(*form2);
	//	Jonh.executeForm(*form2);
	//	Jonh.executeForm(*form2);
	//	Jonh.executeForm(*form2);
	//	Jonh.executeForm(*form2);
	//	Jonh.executeForm(*form2);
	//	Jonh.executeForm(*form3);

		std::cout << "\033[35m"<< "delete Form" << "\033[0m" << std::endl;
		delete form1;
		delete form2;
		delete form3;
	}
	catch (Bureaucrat::GradeTooHighException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (AForm::GradeTooHighException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (AForm::GradeTooLowException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (AForm::NotSignedException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
