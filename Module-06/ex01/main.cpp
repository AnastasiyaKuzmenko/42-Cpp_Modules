/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:19:28 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/19 12:06:22 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    std::cout << "\033[35m" << " test1 " << "\033[0m" << std::endl;
	Data d;
	d.str = "hello";
	d.num = 42;
	Data *ptr =  Serializer::deserialize(Serializer::serialize(&d));
	std::cout << ptr->str <<std::endl;
	std::cout << ptr->num <<std::endl;

    std::cout << "\033[35m" << " test2 " << "\033[0m" << std::endl;
	Data b;
	b.str = "";
	b.num = -42;
	Data *ptr1 =  Serializer::deserialize(Serializer::serialize(&b));
	std::cout << ptr1->str <<std::endl;
	std::cout << ptr1->num <<std::endl;

    return 0;
}
