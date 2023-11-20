/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:33:23 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/27 15:43:00 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main (int argc, char **argv)
{
	Harl new_harl;
	
	if (argc < 2)
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 1;
	}
	else if (argc > 2)
	{
		std::cerr << "[ Too many arguments ]" << std::endl;
		return 1;
	}
	new_harl.filter(argv[1]);
	return 0;
}
