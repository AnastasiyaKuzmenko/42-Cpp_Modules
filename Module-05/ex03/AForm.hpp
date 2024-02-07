/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:59:07 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/01/29 17:44:47 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include <stdlib.h> 
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_required_sign_grade;
	const int			_required_execute_grade;
public:
	AForm();
	AForm(std::string name, const int sign_grade, const int execute_grade);
	AForm(const AForm &source);
	AForm &operator=(const AForm &source);
	virtual ~AForm();


	// exception
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class NotSignedException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	std::string getName() const;
	bool getIsSigned() const;
	int getRequiredSignGrade() const;
	int getRequiredExecuteGrade() const;
	void beSigned(Bureaucrat &b);

    // ex02
    virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream &operator<<(std::ostream &output, AForm const &object);

#endif
