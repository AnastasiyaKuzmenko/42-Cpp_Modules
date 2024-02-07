/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:59:28 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/05 14:34:26 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Required grades: sign 145, exec 137

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm: default constructor started" << std::endl;
	this->_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm: string constructor started" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source) :
AForm(source.getName(), source.getRequiredSignGrade(), source.getRequiredExecuteGrade())
{
	std::cout << "ShrubberyCreationForm: copy constructor called" << std::endl;
	*this = source;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source)
{
	std::cout << "ShrubberyCreationForm: copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->_target = source.getTarget();
	}
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
		std::ofstream	outfile;
		outfile.open((this->_target + "_shrubbery").c_str());
		if(outfile.is_open())
		{
			outfile << "    *    " << std::endl;
			outfile << "   /.\\  " << std::endl;
			outfile << "  /o..\\ " << std::endl;
			outfile << "  /..o\\ " << std::endl;
			outfile << " /.o..o\\" << std::endl;
			outfile << " /...o.\\" << std::endl;
			outfile << "/..o....\\" << std::endl;
			outfile << "^^^[_]^^^" << std::endl;
			outfile.close();
		}
	}
}
