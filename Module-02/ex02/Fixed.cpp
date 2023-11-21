/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:05:39 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/03 13:58:47 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_point = 0;
}

Fixed::Fixed(const int number)
{
	this->fixed_point = number << this->bits;
}

Fixed::Fixed(const float number)
{
	this->fixed_point = std::roundf(number * (1 << this->bits));
}

Fixed::Fixed(const Fixed &source)
{
	*this = source;
}

Fixed &Fixed::operator=(const Fixed &rh)
{
	if (this != &rh)
	{
		this->setRawBits(rh.getRawBits());
	}
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	float value = (float)this->fixed_point/(float)(1 << this->bits); 
	return value;
}

int Fixed::toInt(void) const
{
	return (this->fixed_point >> this->bits);
}

std::ostream &operator<<(std::ostream &output, Fixed const &object)
{
	output<<object.toFloat();
	return output;
}

// The 6 comparison operators

bool Fixed::operator>(Fixed &rh) const
{
	return(this->getRawBits() > rh.getRawBits());
}

bool Fixed::operator<(Fixed &rh) const
{
	return(this->getRawBits() < rh.getRawBits());
}

bool Fixed::operator>=(Fixed &rh) const
{
	return(this->getRawBits() >= rh.getRawBits());
}

bool Fixed::operator<=(Fixed &rh) const
{
	return(this->getRawBits() <= rh.getRawBits());
}

bool Fixed::operator==(Fixed &rh) const
{
	return(this->getRawBits() == rh.getRawBits());
}

bool Fixed::operator!=(Fixed &rh) const
{
	return(this->getRawBits() != rh.getRawBits());
}

// The 4 arithmetic operators

Fixed Fixed::operator+(const Fixed &rh) const
{
	float left_value = this->toFloat();
	float right_value = rh.toFloat();
	return(Fixed(left_value + right_value));
}

Fixed Fixed::operator-(const Fixed &rh) const
{
	float left_value = this->toFloat();
	float right_value = rh.toFloat();
	return(Fixed(left_value - right_value));
}

Fixed Fixed::operator/(const Fixed &rh) const
{
	float left_value = this->toFloat();
	float right_value = rh.toFloat();
	return(Fixed(left_value / right_value));
}

Fixed Fixed::operator*(const Fixed &rh) const
{
	float left_value = this->toFloat();
	float right_value = rh.toFloat();
	return(Fixed(left_value * right_value));
}

// The 4 increment/decrement operators

// pre-increment	++a
Fixed Fixed::operator++()
{
	this->fixed_point++;
	return(*this);
}

// pre-decrement	--a
Fixed Fixed::operator--()
{
	this->fixed_point--;
	return(*this);
}

//post-increment	a++
Fixed Fixed::operator++(int)
{
	Fixed tmp;
	tmp.fixed_point = this->fixed_point;
	++this->fixed_point;
	return tmp;
}

//post-decrement	a--
Fixed Fixed::operator--(int)
{
	Fixed tmp;
	tmp.fixed_point = this->fixed_point;
	--this->fixed_point;
	return tmp;
}

// min - max functions

Fixed &Fixed::min(Fixed &left_value, Fixed &right_value)
{
	if (left_value.getRawBits() < right_value.getRawBits())
		return left_value;
	else
		return right_value;
}

Fixed &Fixed::max(Fixed &left_value, Fixed &right_value)
{
	if (left_value.getRawBits() > right_value.getRawBits())
		return left_value;
	else
		return right_value;
}

const Fixed &Fixed::min(Fixed  const &left_value, Fixed const &right_value)
{
	if (left_value.getRawBits() < right_value.getRawBits())
		return left_value;
	else
		return right_value;
}

const Fixed &Fixed::max(Fixed const &left_value, Fixed const &right_value)
{
	if (left_value.getRawBits() > right_value.getRawBits())
		return left_value;
	else
		return right_value;
}
