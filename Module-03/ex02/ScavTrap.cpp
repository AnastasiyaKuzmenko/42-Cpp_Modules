/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:21:20 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/07 12:54:10 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->name = "Default";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap String constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->name = name;
}

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = source;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &source)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->name = source.getName();
		this->hit_points = source.getHitPoints();
		this->energy_points = source.getEnergyPoints();
		this->attack_damage = source.getAttackDamage();
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

// Member functions

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now on guard mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->hit_points << " points of damage!" << std::endl;
		this->energy_points--;
	}
	else 
	{
		std::cout<< "ScavTrap " << this->name<<" cannot attack"<<std::endl;
	}
}
