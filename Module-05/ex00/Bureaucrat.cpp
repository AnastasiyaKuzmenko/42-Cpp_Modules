/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:26:47 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/01/18 11:33:31 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE)
{
	std::cout << "Bureaucrat: default constructor started" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name.empty() ? "Default" : name), _grade(LOWEST_GRADE)
{
	std::cout << "Bureaucrat: string constructor started" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default")
{
	std::cout << "Bureaucrat: int constructor started" << std::endl;
	if (grade > LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	else if (grade < HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
	else
	{
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name.empty() ? "Default" : name)
{
	std::cout << "Bureaucrat: constructor started" << std::endl;
	if (grade > LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	else if (grade < HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
	else
	{
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &source)
{
	std::cout << "Bureaucrat: copy constructor called" << std::endl;
	*this = source;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
	std::cout << "Bureaucrat: copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->_grade = source._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: destructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade > HIGHEST_GRADE)
	{
		this->_grade--;
	}
	else
	{
		throw GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade < LOWEST_GRADE)
	{
		this->_grade++;
	}
	else
	{
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &object)
{
	output << object.getName() << ", bureaucrat grade " << object.getGrade();
	return output;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade is too low.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade is too high.");
}
