/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:01:11 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/16 14:05:49 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

#include <iostream> 

template< typename T >
void swap( T &a, T &b )
{
	T tmp;
	
	tmp = a;
	a = b;
	b = tmp; 
}

template< typename T >
T const min( T a, T b )
{
	return a < b ? a : b;
}

template< typename T >
T const max( T a, T b )
{
	return a > b ? a : b;
}

#endif