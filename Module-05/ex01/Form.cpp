/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:34:19 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/01/29 15:54:06 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default form"), _is_signed(false),
_required_sign_grade(LOWEST_GRADE),
_required_execute_grade(LOWEST_GRADE)
{
	std::cout << "Form: default constructor started" << std::endl;
}

Form::Form(std::string name, const int sign_grade, const int execute_grade) :
_name(name.empty() ? "Default form" : name),
_is_signed(false),
_required_sign_grade(sign_grade),
_required_execute_grade(execute_grade)
{
	std::cout << "Form: constructor started" << std::endl;
	if (sign_grade > LOWEST_GRADE || execute_grade > LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	if (sign_grade < HIGHEST_GRADE || execute_grade < HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
}

Form::Form(const Form &source) :
_name(source.getName()),
_required_sign_grade(source.getRequiredSignGrade()),
_required_execute_grade(source.getRequiredExecuteGrade())
{
	std::cout << "Form: copy constructor called" << std::endl;
	*this = source;
}

Form &Form::operator=(const Form &source)
{
	std::cout << "Form: copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->_is_signed = source.getIsSigned();
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form: destructor called" << std::endl;
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_is_signed);
}

int Form::getRequiredSignGrade() const
{
	return (this->_required_sign_grade);
}

int Form::getRequiredExecuteGrade() const
{
	return (this->_required_execute_grade);
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getRequiredSignGrade())
	{
		throw GradeTooLowException();
	}
	this->_is_signed = true;
}

std::ostream &operator<<(std::ostream &output, Form const &object)
{
	output << "Form name: " << object.getName() << std::endl;
	output << "Is signed: " << object.getIsSigned() << std::endl;
	output << "Required grade to sign: " << object.getRequiredSignGrade() << std::endl;
	output << "Required grade to executee: " << object.getRequiredExecuteGrade() << std::endl;
	return output;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low.");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high.");
}
