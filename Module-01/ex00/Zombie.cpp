/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:34:06 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/30 16:33:57 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is destroyed..." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
