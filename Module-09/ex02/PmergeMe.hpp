/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:11:31 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/03/05 20:51:11 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <sys/time.h>

class PmergeMe
{
private:
	int					_size;
	bool				_sorted;
	std::vector<int>	_vector;
	std::deque<int>		_deque;
	double              _deltaTimeVector;
	double              _deltaTimeDeque;

	double getTime();
	double deltaTime(long long time);

	void printArray();
	void printTime(std::string flagTypeContainer) const;

	std::vector<int> parseArgsToVector(int argc, char **argv);
	std::deque<int> parseArgsToDeque(int argc, char **argv);

public:
   	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& source);
	PmergeMe	&operator=(const PmergeMe& source);
	~PmergeMe();

	void sortAndMeasureTime();
	template <typename T>
	void mergeInsertSort(T& container);
	double	getVectorDeltaTime(void) const;
	double	getDequeDeltaTime(void) const;

//Exceptions
	class	InvalidArgumentException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
	class	containerTypeException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
};

std::ostream&	operator<<(std::ostream& o, const PmergeMe& i);



template <typename T>
void PmergeMe::mergeInsertSort(T& container)
{
	const int size = container.size();
	if (size < 2)
		return ;
	typename T::iterator middle = container.begin() + size / 2;
	T left(container.begin(), middle);
	T right(middle, container.end());
	mergeInsertSort(left);
	mergeInsertSort(right);
	typename T::iterator i = left.begin();
	typename T::iterator j = right.begin();
	typename T::iterator k = container.begin();
	while (i != left.end() && j != right.end())
	{
		if (*i < *j)
		{
			*k = *i;
			++i;
		}
		else
		{
			*k = *j;
			++j;
		}
		++k;
	}
	while (i != left.end())
	{
		*k = *i;
		++i;
		++k;
	}
	while (j != right.end())
	{
		*k = *j;
		++j;
		++k;
	}
}

#endif
