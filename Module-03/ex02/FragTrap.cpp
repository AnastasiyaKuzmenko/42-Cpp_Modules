/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:21:51 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/07 12:53:34 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	this->name = "Default";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap String constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	this->name = name;
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = source;
}

FragTrap &FragTrap::operator=(const FragTrap &source)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->name = source.getName();
		this->hit_points = source.getHitPoints();
		this->energy_points = source.getEnergyPoints();
		this->attack_damage = source.getAttackDamage();
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout<<"Anyone up for a celebratory high-five?"<<std::endl;
}
