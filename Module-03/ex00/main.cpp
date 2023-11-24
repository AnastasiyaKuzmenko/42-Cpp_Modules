/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:33:23 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/13 15:38:01 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void show_status(ClapTrap &clapTrap)
{
	std::cout << "\033[32m"<< clapTrap.getName()
		<< " Hit points: "
		<< clapTrap.getHitPoints()
		<< " Energy points: "
		<< clapTrap.getEnergyPoints()
		<< " Attack damage: "
		<< clapTrap.getAttackDamage()
		<< "\033[0m"<< std::endl;
}

int main ()
{
	ClapTrap a("Predator");
	ClapTrap b("Aliens");
	ClapTrap c;

	show_status(a);
	show_status(b);
	show_status(c);
	std::cout << std::endl;

	a.beRepaired(1);
	a.attack(b.getName());
	show_status(a);
	show_status(b);
	std::cout << std::endl;

	a.takeDamage(5);
	show_status(a);
	show_status(b);
	std::cout << std::endl;

	a.beRepaired(4);
	show_status(a);
	show_status(b);
	std::cout << std::endl;

	a.takeDamage(10);
	show_status(a);
	show_status(b);
	std::cout << std::endl;

	a.beRepaired(5);
	a.attack(b.getName());
	std::cout << std::endl;

	for (int i = 0; i <= 10; i++)
	{
		b.attack("Ripley");
	}
	show_status(b);
	b.beRepaired(10);
	show_status(b);

	return 0;
}
