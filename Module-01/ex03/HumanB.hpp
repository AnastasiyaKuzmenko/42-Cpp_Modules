/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:23:03 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/20 17:20:54 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon *weapon;
public:
	HumanB(std::string input);
	~HumanB();
	void attack(void);
	void setWeapon(Weapon &w);
};

#endif
