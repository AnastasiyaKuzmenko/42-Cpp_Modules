/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:22:58 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/27 13:20:43 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string input)
{
	this->name = input;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &w)
{
	this->weapon = &w;
}
