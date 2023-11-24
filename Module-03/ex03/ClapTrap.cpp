/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:19:57 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/13 15:55:52 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
	this->name = "Default";
}

ClapTrap::ClapTrap(std::string name): hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "String constructor called" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->name = source.getName();
		this->hit_points = source.getHitPoints();
		this->energy_points = source.getEnergyPoints();
		this->attack_damage = source.getAttackDamage();
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

// get and set functions

std::string ClapTrap::getName() const
{
	return (this->name);
}

void ClapTrap::setHitPoints(int value)
{
	this->hit_points = value;
}
int ClapTrap::getHitPoints() const
{
	return (this->hit_points);
}

void ClapTrap::setEnergyPoints(int value)
{
	this->energy_points = value;
}
int ClapTrap::getEnergyPoints() const
{
	return (this->energy_points);
}

void ClapTrap::setAttackDamage(int value)
{
	this->attack_damage = value;
}
int ClapTrap::getAttackDamage() const
{
	return (this->attack_damage);
}

// Member functions

void ClapTrap::attack(const std::string& target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->hit_points << " points of damage!" << std::endl;
		this->energy_points--;
	}
	else 
	{
		std::cout<< "ClapTrap " << this->name<<" cannot attack"<<std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points > 0)
	{
		hit_points -= amount;
			std::cout <<"ClapTrap " << this->name << " took " << amount << " hit points damage." << std::endl;
		if (hit_points < 0)
		{
			hit_points = 0;
			std::cout <<"ClapTrap " << this->name << " is died."<<std::endl;
		}
	}
	else
	{
		std::cout<< "ClapTrap " <<this->name<<" is already dead"<<std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points <= 0 || this->hit_points <= 0 || amount <= 0)
	{
		std::cout<< "ClapTrap " << this->name<<" cannot be repaired "<<std::endl;
	}
	else
	{
		this->energy_points--;
		this->hit_points += amount;
		std::cout << "ClapTrap " << this->name << " is reparing itself and got more " << amount << " hit points." << std::endl;
	}
}
