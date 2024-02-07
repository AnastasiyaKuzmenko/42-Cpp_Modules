/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:16:06 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/01/30 17:16:36 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern: default constructor started" << std::endl;
}

Intern::Intern(const Intern &source)
{
	std::cout << "Intern: copy constructor called" << std::endl;
	*this = source;
}

Intern &Intern::operator=(const Intern &source)
{
	std::cout << "Intern: copy assignment operator called" << std::endl;
	(void) source;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern: destructor called" << std::endl;
}

AForm *Intern::makeShrubberyForm(std::string const target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makePresidentialForm(std::string const target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyForm(std::string const target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeForm(std::string form_name, std::string target)
{

	static AForm* (*func[])(std::string const target) =
	{
		&Intern::makeShrubberyForm,
		&Intern::makePresidentialForm,
		&Intern::makeRobotomyForm
	};

	std::string names[] = {"shubbery creation", "presidental pardon", "robotomy request"};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == names[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return (func[i](target));
		}
	}
	std::cout << "Intern couldn't create form because " << form_name << " is not recognized." << std::endl;
	return (NULL);
}
