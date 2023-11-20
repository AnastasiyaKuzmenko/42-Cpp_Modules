/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:23:10 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/27 13:21:29 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string input)
{
	this->type = input;
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string input)
{
	this->type = input;
}

std::string Weapon::getType() const
{
	return (this->type);
}
