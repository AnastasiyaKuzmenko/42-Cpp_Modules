/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:27:50 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/06 16:34:50 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
try
	{
		std::cout << "\033[35m"<< "Intern create form" << "\033[0m" << std::endl;
		Intern 		someRandomIntern = Intern();
		AForm*		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (!rrf)
			return 0;
		std::cout << "\033[35m"<< "Create Bureaucrat" << "\033[0m" << std::endl;
		Bureaucrat Jonh = Bureaucrat("Jonh", 25);

		std::cout << *rrf;

		std::cout << "\033[35m"<< "Sign Form" << "\033[0m" << std::endl;
		Jonh.signForm(*rrf);

		std::cout << "\033[35m"<< "Exec Form" << "\033[0m" << std::endl;
		Jonh.executeForm(*rrf);

		std::cout << "\033[35m"<< "delete Form" << "\033[0m" << std::endl;
		delete rrf;
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
