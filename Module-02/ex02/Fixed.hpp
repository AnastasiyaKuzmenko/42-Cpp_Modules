/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:05:35 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/29 15:34:29 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int fixed_point;
	static const int bits = 8;

public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed &source);
	Fixed &operator=(const Fixed &rh);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(Fixed &rh)const;
	bool operator<(Fixed &rh)const;
	bool operator>=(Fixed &rh)const;
	bool operator<=(Fixed &rh)const;
	bool operator==(Fixed &rh)const;
	bool operator!=(Fixed &rh)const;

	Fixed operator+(const Fixed &rh) const;
	Fixed operator-(const Fixed &rh) const;
	Fixed operator/(const Fixed &rh) const;
	Fixed operator*(const Fixed &rh) const;

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);

	static const Fixed &min(Fixed  const &a, Fixed const &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);

};

	std::ostream &operator<<(std::ostream &output, Fixed const &object);

#endif
