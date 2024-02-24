/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:51:49 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/24 12:41:18 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template < typename T >
class Array
{
private:
	T*				_array;
	unsigned int	_size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& source);
	~Array();

	Array&	operator=(const Array& source);
	T&		operator[](unsigned int index) const;
	unsigned int	size() const;

	class OutOfBoundsException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};


template< typename T >
Array<T>::Array(): _array(NULL), _size(0)
{ }

template <typename T>
Array<T>::Array(unsigned int n):_array(new T[n]), _size(n)
{ }

template< typename T >
Array<T>::~Array()
{
	if (this->_array != NULL)
	{
		delete [] this->_array;
	}
}

template< typename T >
Array<T>::Array(const Array& source)
{
	this->_size = source._size;
	this->_array = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++)
	{
		this->_array[i] = source._array[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& source)
{
	if (this == &source)
	{
		return (*this);
	}
	if(this->_array != NULL)
	{
		delete [] this->_array;
	}
	this->_size = source._size;
	this->_array = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++)
	{
		this->_array[i] = source._array[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size || this->_array == nullptr)
	{
		std::cout <<"\033[35m" << "Invalid access to index " << index << ": " << "\033[0m";
		throw Array<T>::OutOfBoundsException();
	}
	return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index is out of bounds");
}


#endif
