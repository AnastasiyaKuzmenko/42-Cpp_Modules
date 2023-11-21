/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:00:57 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/03 14:06:46 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	}
/*
	{
	std::cout <<std::endl;
	std::cout<< "\033[1m\033[35m An additional test \033[0m" <<std::endl;
	Fixed a(8.5f);
	Fixed b(4.5f);

	std::cout<< "\033[35ma = " << a<< "\033[0m" <<std::endl;

	std::cout<< "\033[35mb = "<< b << "\033[0m"<<std::endl<<std::endl;

	std::cout<< "a > b: " << (a > b) <<std::endl;
	std::cout<< "a < b: " << (a < b) <<std::endl;
	std::cout<< "a >= b: " << (a >= b) <<std::endl;
	std::cout<< "a <= b: " << (a <= b) <<std::endl;
	std::cout<< "a == b: " << (a == b) <<std::endl;
	std::cout<< "a != b: " << (a != b) <<std::endl<<std::endl;

	std::cout<< "a + b: "<< (a + b) <<std::endl;
	std::cout<< "a - b: "<< (a - b) <<std::endl;
	std::cout<< "a / b: "<< (a / b) <<std::endl;
	std::cout<< "a * b: "<< (a * b) <<std::endl<<std::endl;

	std::cout<< "a++:" <<std::endl;
	std::cout<< (a++) <<std::endl;
	std::cout<< "a after ++:" <<std::endl;
	std::cout<< (a) <<std::endl<<std::endl;

	std::cout<< "++a:" <<std::endl;
	std::cout<< (++a) <<std::endl<<std::endl;

	std::cout<< "a--:" <<std::endl;
	std::cout<< (a--) <<std::endl;
	std::cout<< "a after --:" <<std::endl;
	std::cout<< (a) <<std::endl<<std::endl;

	std::cout<< "--a:" <<std::endl;
	std::cout<< (--a) <<std::endl<<std::endl;

	std::cout<< "find min: "<< a.min(a, b) <<std::endl;
	std::cout<< "find max: " << b.max(a, b) <<std::endl;
	}
*/	
	return 0;
}
