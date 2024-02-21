/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:46:39 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/15 11:49:36 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <regex>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <float.h>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define PSEUDOLITERAL 5

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &source);
	ScalarConverter &operator=(const ScalarConverter &source);
	~ScalarConverter();

	static void printChar(char value);
	static void printInt(int value);
	static void printFloat(float value);
	static void printDouble(double value);
	static void printPseudoLiteral(std::string &input);

	static void parseChar(const std::string &str);
	static void parseInt(const std::string &str);
	static void parseFloat(const std::string &str);
	static void parseDouble(const std::string &str);

	static bool isChar(std::string &str);
	static bool isInt(std::string &str);
	static bool isFloat(std::string &str);
	static bool isDouble(std::string &str);
	static bool isPseudoLiteral(std::string &str);
	
	static char		_charValue;
	static int		_intValue;
	static float	_floatValue;
	static double 	_doubleValue;

	static bool		_isLimitChar;
	static bool		_isLimitInt;
	static bool		_isLimitFloat;
	static bool		_isLimitDouble;

	static void findType(std::string &input);
	static void	checkLimits(std::string str);

	static int	_type;

public:
	static void convert(std::string &input);

};


#endif
