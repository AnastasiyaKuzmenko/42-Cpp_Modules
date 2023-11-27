/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:01:02 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/19 16:13:12 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Character Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string name): _name(name)
{
	std::cout << "Character String constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(Character const &source) : _name(source._name)
{
	std::cout << "Character Copy constructor called" << std::endl;
	*this = source;
}

Character& Character::operator=(Character const &source)
{
	if (this != &source)
	{
		this->_name = source._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
			{
				delete this->_inventory[i];
			}
			if (source._inventory[i])
			{
				this->_inventory[i] = source._inventory[i]->clone();
			}
			else
			{
				this->_inventory[i] = NULL;
			}
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "Character " << this->_name << " equipped with " << m->getType() << std::endl;
			return;
		}
	}
	delete m;
	std::cout << "Character " << this->_name << " can't equip " << m->getType() << std::endl;
}

void	Character::unequip(int idx)
{
	if (this->_inventory[idx] != NULL && idx < 4)
	{
		this->_inventory[idx] = NULL;
		std::cout << "Character " << this->_name << " unequipped" << std::endl;
	}
	else
		std::cout << "Character " << this->_name << " can't unequip" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (this->_inventory[idx]!= NULL && idx < 4)
	{
		this->_inventory[idx]->use(target);
		std::cout << "Character " << this->_name << " uses " << this->_inventory[idx]->getType() << std::endl;
	}
	else
		std::cout << "Character " << this->_name << " can't use" << std::endl;
}

AMateria* Character::getDrop(int idx)
{
	return (this->_inventory[idx]);
}
