/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:34:37 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/01/29 15:54:28 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_required_sign_grade;
	const int			_required_execute_grade;
public:
	Form();
	Form(std::string name, const int sign_grade, const int execute_grade);
	Form(const Form &source);
	Form &operator=(const Form &source);
	~Form();


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

	std::string getName() const;
	bool getIsSigned() const;
	int getRequiredSignGrade() const;
	int getRequiredExecuteGrade() const;
	void beSigned(Bureaucrat &b);

};

std::ostream &operator<<(std::ostream &output, Form const &object);

#endif
