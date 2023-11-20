/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:33:23 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/27 13:05:10 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main ()
{
	int amount = 15;
	Zombie *horde_zombie = zombieHorde(amount, "ZoMbIe");

	for (int i = 0; i < amount; i++)
	{
		horde_zombie[i].announce();
	}
	delete [] horde_zombie;
	return 0;
}
