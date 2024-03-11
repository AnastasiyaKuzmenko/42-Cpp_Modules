/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:11:27 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/03/05 20:50:06 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **argv): _size(argc - 1), _sorted(false)
{
	parseArgsToVector(argc, argv);
	parseArgsToDeque(argc, argv);

}
PmergeMe::PmergeMe(const PmergeMe& source)
{
	*this = source;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe& source)
{
	if (this != &source)
	{
		this->_sorted = source._sorted;
		this->_size = source._size;
		this->_vector = source._vector;
		this->_deque = source._deque;
		this->_deltaTimeVector = source._deltaTimeVector;
		this->_deltaTimeDeque = source._deltaTimeDeque;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

std::ostream&	operator<<(std::ostream& o, const PmergeMe& i)
{
	o 
		<< "Vector delta time: " << i.getVectorDeltaTime() << std::endl
		<< "Deque delta time: " << i.getDequeDeltaTime();
	return o;
}

// Get functions

double	PmergeMe::getVectorDeltaTime(void) const
{
	return (this->_deltaTimeVector);
}
double	PmergeMe::getDequeDeltaTime(void) const
{
	return (this->_deltaTimeDeque);
}


//Parse

std::vector<int> PmergeMe::parseArgsToVector(int argc, char **argv)
{
	_vector.clear();
	for (int i = 1; i < argc; i++)
	{
		for (char *c = argv[i]; *c != '\0'; c++)
		{
			if (!std::isdigit(*c))
			{
				throw InvalidArgumentException();
			}
		}
		std::string arg = argv[i];
		int value = std::atoi(arg.c_str());
		if (value < 0)
		{
			throw InvalidArgumentException();
		}
		_vector.push_back(value);
	}
	return _vector;
}

std::deque<int> PmergeMe::parseArgsToDeque(int argc, char **argv)
{
	_deque.clear();
	for (int i = 1; i < argc; i++)
	{
		for (char *c = argv[i]; *c != '\0'; c++)
		{
			if (!std::isdigit(*c))
			{
				throw InvalidArgumentException();
			}
		}
		std::string arg = argv[i];
		int value = std::atoi(arg.c_str());
		if (value < 0)
		{
			throw InvalidArgumentException();
		}
		_deque.push_back(value);
	}
	return _deque;
}

// Time functions
double PmergeMe::getTime()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

double PmergeMe::deltaTime(long long time)
{
	if (time > 0)
	{
		return (getTime()-time);
	}
	return 0;
}

// Sort functions
void PmergeMe::sortAndMeasureTime()
{
	printArray();

	double tBegin = getTime();
	mergeInsertSort(_vector);
	_deltaTimeVector = deltaTime(tBegin);

	tBegin = getTime();
	mergeInsertSort(_deque);
	_deltaTimeDeque = deltaTime(tBegin);

	_sorted = true;
	printArray();

	printTime("vector");
	printTime("deque");
}


// Print functions

void PmergeMe::printArray()
{
	if (this->_sorted == false)
	{
		std::cout << "Before: ";
	}
	else
	{
		std::cout << "After: ";
	}

	for(std::vector<int>::iterator it =_vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void PmergeMe::printTime(std::string flagContainerType) const
{

	double deltaTime;
	if (flagContainerType == "vector")
		deltaTime = _deltaTimeVector;
	else if (flagContainerType == "deque")
		deltaTime = _deltaTimeDeque;
	else
		throw containerTypeException();
	std::cout 
		<< "Time to process a range of " << _size 
		<< " elements with std::" << flagContainerType << ": "
		<< std::fixed << std::setprecision(5) << deltaTime << " ms" << std::endl;
}

// Exception

const char	*PmergeMe::InvalidArgumentException::what(void) const throw()
{
	return ("Error: invalid arguments.");
}

const char	*PmergeMe::containerTypeException::what(void) const throw()
{
	return ("Error: container choosen to print is not vector or deque.");
}

