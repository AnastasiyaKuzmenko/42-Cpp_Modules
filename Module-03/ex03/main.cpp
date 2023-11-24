/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:33:23 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/13 16:34:14 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

int	main()
{
	DiamondTrap a("Predator");

	std::string enemy = "Aliens";
	show_status(a);
	a.whoAmI();
	a.attack(enemy);
	show_status(a);
	a.takeDamage(20);
	show_status(a);

	return 0;
}

/*
int main ()
{
	DiamondTrap a("Predator");
	DiamondTrap b("Aliens");
	DiamondTrap c;
	std::string enemy = "Monster";

	show_status(a);
	show_status(b);
	show_status(c);
	std::cout << std::endl;

	a.whoAmI();
	a.attack(enemy);
	a.takeDamage(5);
	show_status(a);
	show_status(b);
	std::cout << std::endl;

	a.beRepaired(5);
	show_status(a);
	show_status(b);
	std::cout << std::endl;

	a.takeDamage(10);
	show_status(a);
	show_status(b);
	std::cout << std::endl;

	for (int i = 0; i <= 10; i++)
		b.attack(enemy);
	show_status(b);
	b.beRepaired(10);
	show_status(b);

	return 0;
}
*/