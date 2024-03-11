/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:06:07 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/03/05 12:56:03 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	std::ifstream inputFile(argv[1]);
	if (inputFile.is_open() == false)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange exchange("data.csv");
		std::string line;
		std::getline(inputFile, line);
		while (std::getline(inputFile, line))
		{
			std::stringstream ss(line);
			std::string date;
			float value;
			if (std::getline(ss, date, '|') && ss >> value)
			{
				date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
				date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
				try
				{
					float exchangeRate = exchange.getExchangeRate(date, value);
					float result = value * exchangeRate;
					std::cout << date << " => " << value << " = " << result << std::endl;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			else
			{
				std::cerr << "Error: bad input => " << line << std::endl;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
