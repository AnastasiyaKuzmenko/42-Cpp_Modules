/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:48:27 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/30 16:34:35 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->name << " is destroyed..." << std::endl;
}

void Zombie::setName(std::string str)
{
	this->name = str;
}

std::string Zombie::getName(void)
{
	return (this->name);
}

void Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
