/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:29:23 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/27 14:23:44 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _size(0)
{

}
Span::Span(unsigned int n): _size(n)
{

}

Span::Span(const Span& source)
{
	*this = source;
}

Span &Span::operator=(const Span& source)
{
	if (this != &source)
	{
		this->_size = source._size;
		this->_data = source._data;
	}
	return *this;
}

Span::~Span()
{
}


std::vector<int>& Span::getData()
{
	return(_data);
}

void Span::addNumber(int n)
{
	if (_data.size() < this->_size)
		_data.push_back(n);
	else
		throw Span::FullStorageException();
}

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	for (; start != end; ++start)
	{
		addNumber(*start);
	}
}

unsigned int Span::shortestSpan(void)
{
	if (this->_data.size() <= 1)
	{
		throw (NotEnoughNumbersException());
	}
	std::sort(this->_data.begin(), this->_data.end());
	int	min_diff = 2147483647;
	for(unsigned int i = 0; i < this->_size - 1; i++)
	{
		if (this->_data[i + 1] - this->_data[i] < min_diff)
		{
			min_diff = this->_data[i + 1] - this->_data[i];
		}
	}
	return min_diff;
}

unsigned int Span::longestSpan(void)
{
	if (this->_data.size() <= 1)
		throw (NotEnoughNumbersException());

	std::vector<int>::iterator	max;
	std::vector<int>::iterator	min;

	max = std::max_element(this->_data.begin(), this->_data.end());
	min = std::min_element(this->_data.begin(), this->_data.end());

	return (*max-*min);
}

// Exception

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return ("There is no enough elements in Span");
}

const char* Span::FullStorageException::what() const throw()
{
	return ("Span is full");
}
