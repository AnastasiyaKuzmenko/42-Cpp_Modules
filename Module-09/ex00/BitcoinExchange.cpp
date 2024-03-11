/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:05:58 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/03/05 13:07:54 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile)
{
	std::ifstream file(databaseFile.c_str());
	if (!file || !file.is_open())
	{
		throw RuntimeErrorException();
	}
	
	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			continue;
		}
		std::stringstream ss(line);
		std::string date;
		float price;
		if (std::getline(ss, date, ',') && ss >> price)
		{
			_exchangeRates[date] = price;
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source)
{
	*this = source;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& source)
{
	if (this != &source)
	{
		this->_exchangeRates = source._exchangeRates;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

bool	BitcoinExchange::isValidValue(float value) const
{	
	if (value < 0)
	{
		throw (NegativeNumberException());
	}
	if (value > 1000)
	{
		throw (TooBigNumberException());
	}
	return true;
}

bool	BitcoinExchange::isValidDate(const std::string input_line) const
{
	int year, month, day;
	char separator;

	std::istringstream ss(input_line);
	ss >> year >> separator >> month >> separator >> day;

	if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0)
	{
		return false;
	}
	if (month == 2)
	{
		if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			if (day > 29)
			{
				return false;
			}
		}
		else 
		{
			if (day > 28)
			{
				return false;
			}
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if(day > 30)
		{
			return false;
		}
	}
	return true;
}

float	BitcoinExchange::getExchangeRate(const std::string& date, float value) const
{
	isValidValue(value);
	if (isValidDate(date) == false)
	{
		throw InvalidDataException();
	}
	std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
	if(it == _exchangeRates.end())
	{
		it = _exchangeRates.upper_bound(date);
		if (it == _exchangeRates.begin())
			throw InvalidArgumentException();
		--it;
	}
	return (it->second);
}

std::ostream&	operator<<(std::ostream& o, const BitcoinExchange& i)
{
	(void)i;
	return o;
}


//Exception
const char	*BitcoinExchange::NegativeNumberException::what(void) const throw()
{
	return ("Error: not a positive number.");
}
const char	*BitcoinExchange::TooBigNumberException::what(void) const throw()
{
	return ("Error: too large a number.");
}
const char	*BitcoinExchange::RuntimeErrorException::what(void) const throw()
{
	return ("Error: could not open bitcoin price database file.");
}
const char	*BitcoinExchange::InvalidDataException::what(void) const throw()
{
	return ("Error: invalid data exception.");
}
const char	*BitcoinExchange::InvalidArgumentException::what(void) const throw()
{
	return ("Error: no exchange rate found for given date.");
}
