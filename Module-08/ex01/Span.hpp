/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:29:37 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/27 14:24:11 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	std::vector<int> _data;
	std::size_t _size;
	Span();

public:
	Span(unsigned int n);
	Span(const Span& source);
	Span	&operator=(const Span& source);
	~Span();

	void			addNumber(int x);
	void			addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	std::vector<int>&	getData();

	class FullStorageException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class NotEnoughNumbersException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

};

#endif
