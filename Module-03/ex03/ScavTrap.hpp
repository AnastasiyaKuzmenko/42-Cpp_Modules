/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:21:35 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/07 12:56:26 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap (const ScavTrap &src);
		ScavTrap &operator=(const ScavTrap &rh_src);
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate();
};

#endif
