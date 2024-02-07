/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:59:00 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/01/29 17:20:28 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default form"), _is_signed(false),
_required_sign_grade(LOWEST_GRADE),
_required_execute_grade(LOWEST_GRADE)
{
	std::cout << "AForm: default constructor started" << std::endl;
}

AForm::AForm(std::string name, const int sign_grade, const int execute_grade) :
_name(name.empty() ? "Default form" : name),
_is_signed(false),
_required_sign_grade(sign_grade),
_required_execute_grade(execute_grade)
{
	std::cout << "AForm: constructor started" << std::endl;
	if(sign_grade > LOWEST_GRADE || execute_grade > LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	if(sign_grade < HIGHEST_GRADE || execute_grade < HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
}

AForm::AForm(const AForm &source) :
_name(source.getName()),
_required_sign_grade(source.getRequiredSignGrade()),
_required_execute_grade(source.getRequiredExecuteGrade())
{
	std::cout << "AForm: copy constructor called" << std::endl;
	*this = source;
}

AForm &AForm::operator=(const AForm &source)
{
	std::cout << "AForm: copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->_is_signed = source.getIsSigned();
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm: destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_is_signed);
}

int AForm::getRequiredSignGrade() const
{
	return (this->_required_sign_grade);
}

int AForm::getRequiredExecuteGrade() const
{
	return (this->_required_execute_grade);
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getRequiredSignGrade())
	{
		throw GradeTooLowException();
	}
	this->_is_signed = true;
}

std::ostream &operator<<(std::ostream &output, AForm const &object)
{
	output << "AForm name: " << object.getName() << std::endl;
	output << "Is signed: " << object.getIsSigned() << std::endl;
	output << "Required grade to sign: " << object.getRequiredSignGrade() << std::endl;
	output << "Required grade to execute: " << object.getRequiredExecuteGrade() << std::endl;
	return output;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: Grade is too low.");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: Grade is too high.");
}


const char* AForm::NotSignedException::what() const throw()
{
	return ("AForm: Form cannot be executed since it is not signed.");
}
