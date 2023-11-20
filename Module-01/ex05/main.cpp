/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:33:23 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/31 15:13:26 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main ()
{
	Harl new_harl;
	
	new_harl.complain("DEBUG");
	new_harl.complain("INFO");
	new_harl.complain("WARNING");
	new_harl.complain("ERROR");
	
	return 0;
}
