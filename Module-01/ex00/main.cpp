/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:33:23 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/27 13:01:10 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main ()
{
	Zombie *new_zombie = newZombie("heap Zombie");
	new_zombie->announce();
	
	randomChump("stack Zombie");
	
	delete new_zombie;
	return 0;
}
