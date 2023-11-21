/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:32:23 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/03 13:28:39 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int fixed_point;
	static const int bits = 8;

public:
	Fixed();
	Fixed(const Fixed &source);
	Fixed &operator=(const Fixed &source);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
