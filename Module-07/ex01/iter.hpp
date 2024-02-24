/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:35:27 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/22 13:58:46 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template< typename T >
void iter(T*array, unsigned int length, void(*f)(T const &))
{
	unsigned int i;
	for (i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template< typename T >
void printValue(T const &n)
{
	std::cout << n << std::endl;
}

#endif
