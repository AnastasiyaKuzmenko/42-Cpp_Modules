/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:06:03 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/03/05 13:08:11 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream> //stringstream and isstringstream

class	BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const std::string& databaseFile);
	BitcoinExchange(const BitcoinExchange& source);
	BitcoinExchange	&operator=(const BitcoinExchange& source);
	~BitcoinExchange();


	bool	isValidValue(float value) const;
	bool	isValidDate(const std::string line) const;
	float	getExchangeRate(const std::string& date, float value) const;

//Exceptions
	class	NegativeNumberException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
	class	TooBigNumberException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
	class	RuntimeErrorException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};

	class	InvalidDataException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
	class InvalidArgumentException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};

private:
	std::map<std::string, float> _exchangeRates;

};

std::ostream&	operator<<(std::ostream& o, const BitcoinExchange& i);

#endif
