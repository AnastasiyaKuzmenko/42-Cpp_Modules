/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:10:10 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/03/05 13:13:23 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>

class	RPN
{
private:
	std::stack<int>	_stack;
	int				_result;
public:
	RPN();
	RPN(const RPN& source);
	RPN& operator=(const RPN& source);
	~RPN();


	void	reversePolishNotation(const std::string &input);
	void	calculate(int number1, int number2, char op);
	int		getResult(void) const;

//Exceptions
	class	divisionByZeroException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};

	class	insufficientOperandsException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};

	class	tooManyOperandsException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};

	class	invalidTokenException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
};

std::ostream&	operator<<(std::ostream& o, const RPN& i);

#endif
