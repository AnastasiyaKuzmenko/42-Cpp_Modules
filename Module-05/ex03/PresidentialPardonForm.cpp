/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:59:13 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/05 14:34:08 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//  Required grades: sign 25, exec 5

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm: default constructor started" << std::endl;
	this->_target = "Default";
		
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm: string constructor started" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source) : AForm(source.getName(), source.getRequiredSignGrade(), source.getRequiredExecuteGrade())
{
	std::cout << "PresidentialPardonForm: copy constructor called" << std::endl;
	*this = source;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &source)
{
	std::cout << "PresidentialPardonForm: copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->_target = source.getTarget();
	}
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm: destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

	if (this->getIsSigned() == false)
	{
		std::cout << this->_target << " couldn't be execute because: " << std::endl;
		throw AForm::NotSignedException();
	}
	else if (executor.getGrade() > this->getRequiredExecuteGrade())
	{
		std::cout << this->_target << " couldn't be execute because: " << std::endl;
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}
