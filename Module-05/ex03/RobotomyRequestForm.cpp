/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:59:20 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/05 14:34:17 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Required grades: sign 72, exec 45

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm: default constructor started" << std::endl;
	this->_target = "Default";
		
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm: string constructor started" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) : AForm(source.getName(), source.getRequiredSignGrade(), source.getRequiredExecuteGrade())
{
	std::cout << "RobotomyRequestForm: copy constructor called" << std::endl;
	*this = source;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
	std::cout << "RobotomyRequestForm: copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->_target = source.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
		int rand_value;

    	rand_value = rand();

		if(rand_value % 2 == 0)
    	{
       		std::cout << "RobotomyRequestForm: has been robotomized successfully" << std::endl;
    	}
    	else
    	{
        	std::cout << "RobotomyRequestForm: The robotomy failed" << std::endl;
    	}
	}
}
