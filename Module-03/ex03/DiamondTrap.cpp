/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:46:58 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/13 17:57:33 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	this->name = "Default";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap string constructor called" << std::endl;
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 30;
}

DiamondTrap::DiamondTrap (const DiamondTrap &source) : ClapTrap(source.name + "_clap_name"), ScavTrap(source.name), FragTrap(source.name)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = source;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &source)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->name = source.name;
		this->hit_points = source.FragTrap::hit_points;
		this->energy_points = source.ScavTrap::energy_points;
		this->attack_damage = source.FragTrap::attack_damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->name << " and my Clap name is " << this->FragTrap::name << std::endl;
}

void DiamondTrap::attack(std::string &target)
{
	ScavTrap::attack(target);
}
