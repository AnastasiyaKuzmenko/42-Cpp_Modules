/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:46:34 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/19 12:01:02 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	ScalarConverter::_type = 0;
	std::cout << "ScalarConverter: default constructor started" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &source)
{
	std::cout << "ScalarConverter: copy constructor called" << std::endl;
	*this = source;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source)
{
	std::cout << "ScalarConverter: copy assignment operator called" << std::endl;
	_type = source._type;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter: destructor called" << std::endl;
}

//Static bool-variables instantialization
bool	ScalarConverter::_isLimitChar = false;
bool	ScalarConverter::_isLimitInt = false;
bool	ScalarConverter::_isLimitFloat = false;
bool	ScalarConverter::_isLimitDouble = false;

//Static variables instantialization
int		ScalarConverter::_type = 0;
char	ScalarConverter::_charValue = ' ';
int		ScalarConverter::_intValue = 0;
float	ScalarConverter::_floatValue = 0;
double	ScalarConverter::_doubleValue = 0;


// parse - functions
void ScalarConverter::parseChar(const std::string &str)
{
	_charValue = str[0];
	_intValue = static_cast<int>(_charValue);
	_floatValue = static_cast<float>(_charValue);
	_doubleValue = static_cast<double>(_charValue);
}

void ScalarConverter::parseInt(const std::string &str)
{
	_intValue = std::atoi(str.c_str());
	_charValue = static_cast<char>(_intValue);
	_floatValue = static_cast<float>(_intValue);
	_doubleValue = static_cast<double>(_intValue);
}

void ScalarConverter::parseFloat(const std::string &str)
{
	_floatValue = std::atof(str.c_str());
	_charValue = static_cast<char>(_floatValue);
	_intValue = static_cast<int>(_floatValue);
	_doubleValue = static_cast<double>(_floatValue);
}

void ScalarConverter::parseDouble(const std::string &str)
{
	_doubleValue = std::strtod(str.c_str(), NULL);
	_charValue = static_cast<char>(_doubleValue);
	_intValue = static_cast<int>(_doubleValue);
	_floatValue = static_cast<float>(_doubleValue);
}

// print - functions
void ScalarConverter::printChar(char value)
{
	if (!std::isprint(value))
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else if (_isLimitChar)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		std::cout << "char: '" << value << "'" << std::endl;
	}
}

void ScalarConverter::printInt(int value)
{
	if (_isLimitInt)
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << value << std::endl;
	}
}

void ScalarConverter::printFloat(float value)
{
	if (_isLimitFloat || (_isLimitInt && _type == INT))
	{
		std::cout << "float: impossible" << std::endl;
	}
	else
	{
		std::cout << "float: " << value << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(double value)
{
	if (_isLimitDouble || (_isLimitFloat && _type == FLOAT) || (_isLimitInt && _type == INT))
	{
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << "double: " << value << std::endl;
	}
}
	
void ScalarConverter::printPseudoLiteral(std::string &input)
{
	std::string pseudoLiteralsArray[] = {
		"+inff",
		"-inff",
		"nanf",
		"+inf",
		"-inf",
		"nan"
	};
	for (int i = 0; i < 6; i++)
	{
		if (pseudoLiteralsArray[i] == input)
		{
			if (i >= 0 && i <= 2)
			{
				input[input.length() - 1] = '\0';
			}
		}
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input << "f" << std::endl;
	std::cout << "double: " << input << std::endl;
}

// isType functions

static const std::regex INT_TYPE("\\s*[+-]?[0-9]+\\s*");
static const std::regex DOUBLE_TYPE("\\s*[+-]?[0-9]+[.]?[0-9]+\\s*");
static const std::regex FLOAT_TYPE("\\s*[+-]?[0-9]+[.]?[0-9]+f\\s*");

bool ScalarConverter::isChar(std::string& input)
{
	if(input.length() == 1 && input[1] == '\0' && std::isprint(input[0]) && !std::isdigit(input[0]))
	{
		return true;
	}
	return false;
}

bool ScalarConverter::isInt(std::string& input)
{
	return (std::regex_match(input, INT_TYPE));
}

bool ScalarConverter::isFloat(std::string& input)
{
	return (std::regex_match(input, FLOAT_TYPE));
}

bool ScalarConverter::isDouble(std::string& input)
{
	return (std::regex_match(input, DOUBLE_TYPE));
}

bool ScalarConverter::isPseudoLiteral(std::string& input)
{
	std::string pseudoLiteralsArray[] = {
		"-inff",
		"+inff",
		"nanf",
		"-inf",
		"+inf",
		"nan"
	};
	for (int i = 0; i < 6; i++)
	{
		if (pseudoLiteralsArray[i] == input)
		{
			return true;
		}
	}
	return false;
}

void ScalarConverter::findType(std::string &input)
{
	if (isChar(input))
	{
		_type = CHAR;
	}
	else if (isInt(input))
	{
		_type = INT;
	}
	else if (isFloat(input))
	{
		_type = FLOAT;
	}
	else if (isDouble(input))
	{
		_type = DOUBLE;
	}
	else if (isPseudoLiteral(input))
	{
		_type = PSEUDOLITERAL;
	}
}

void	ScalarConverter::checkLimits(std::string str)
{
	double value = std::strtod(str.c_str(), NULL);
	if (value < 0 || value > 127)
		_isLimitChar = true;
	if (value < INT_MIN || value > INT_MAX)
		_isLimitInt = true;
	if (value < -FLT_MAX|| value > FLT_MAX)
		_isLimitFloat = true;
	if ((value < -DBL_MAX || value > DBL_MAX))
		_isLimitDouble = true;
}


void ScalarConverter::convert(std::string &input)
{
	std::cout << std::fixed << std::setprecision(1); 
	findType(input);
	checkLimits(input);
	
	switch(_type)
	{
		case 1:
			parseChar(input);
			break;
		case 2:
			parseInt(input);
			break;
		case 3:
			parseDouble(input);
			break;
		case 4:
			parseFloat(input);
			break;
		case 5:
			printPseudoLiteral(input);
			break;
		default:
			std::cout << "Error: Invalid input" << std::endl;
	}
	if (_type > 0 && _type < 5)
	{
		printChar(_charValue);
		printInt(_intValue);
		printFloat(_floatValue);
		printDouble(_doubleValue);
	}
}
