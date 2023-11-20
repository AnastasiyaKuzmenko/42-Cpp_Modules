/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:22:17 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/27 13:41:12 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string input, Weapon &w) : weapon(w)
{
	this->name = input;
}

HumanA::~HumanA()
{
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}
