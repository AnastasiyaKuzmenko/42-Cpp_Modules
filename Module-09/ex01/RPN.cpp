/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:10:06 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/03/05 13:31:11 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN( const RPN& source )
{
	*this = source;
}

RPN&	RPN::operator=( const RPN& source )
{
	if (this != &source)
	{
		this->_stack = source._stack;
		this->_result = source._result;
	}
	return (*this);
}

RPN::~RPN()
{
}

void	RPN::calculate(int number1, int number2, char op)
{
	switch (op)
	{
	case '+':
		_stack.push(number1 + number2);
		break;
	case '-':
		_stack.push(number1 - number2);
		break;
	case '*':
		_stack.push(number1 * number2);
		break;
	case '/':
		if (number2 == 0)
		{
			throw divisionByZeroException();
		}
		_stack.push(number1 / number2);
		break;
	}
}

void	RPN::reversePolishNotation(const std::string &input)
{
	std::string token;
	bool is_negative = false;

	for (std::size_t i = 0; i < input.length(); i++)
	{
		char c = input[i];
		if (c == ' ')
		{
			continue ;
		}
		else if (c == '-' &&  isdigit(input[i+1]))
		{
			is_negative = true;
			continue;
		}
		else if (isdigit(c))
		{
			if (is_negative)
			{
				token += '-';
				is_negative = false;
			}
			token += c;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if(_stack.size() < 2)
			{
				throw insufficientOperandsException();
			}
			int number2 = _stack.top();
			_stack.pop();
			int number1 = _stack.top();
			_stack.pop();
			calculate(number1, number2, c);
		}
		else
		{
			throw invalidTokenException();
		}
		if (!token.empty())
		{
			_stack.push(atoi(token.c_str()));
			token.clear();
		}
	}
	if (_stack.size() != 1)
		throw tooManyOperandsException();
	_result = _stack.top();
	_stack.pop();
}

//Exception

const char	*RPN::divisionByZeroException::what(void) const throw()
{
	return ("Error: division by zero.");
}

const char	*RPN::insufficientOperandsException::what(void) const throw()
{
	return ("Error:  insufficient operands.");
}

const char	*RPN::tooManyOperandsException::what(void) const throw()
{
	return ("Error:  too many operands.");
}

const char	*RPN::invalidTokenException::what(void) const throw()
{
	return ("Error:  invalid token.");
}

int	RPN::getResult(void) const
{
	return (this->_result);
}

std::ostream&	operator<<(std::ostream& o, const RPN& i)
{
	o << i.getResult();
	return o;
}
