/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:29:59 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/27 14:24:32 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack<T> &source);
	MutantStack &operator=(const MutantStack<T> &source);
	~MutantStack();

	using std::stack<T>::c;
	typedef typename std::stack<T>::container_type::iterator iterator;
		
	iterator begin();
	iterator end();
};

template <typename T>
MutantStack<T>::MutantStack()
{
 //   std::cout << "MutantStack: default constructor started" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &source): std::stack<T>(source)
{
//    std::cout << "MutantStack: copy constructor called" << std::endl;
//	*this = source;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &source)
{
//   std::cout << "MutantStack: copy assignment operator called" << std::endl;

	if (this != &source)
	{
		std::stack<T>::operator=(source);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
//   std::cout << "MutantStack: destructor called" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

#endif
