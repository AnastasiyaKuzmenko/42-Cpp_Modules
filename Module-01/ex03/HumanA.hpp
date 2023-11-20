/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:22:52 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/20 16:41:18 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon &weapon;
public:
	HumanA(std::string input, Weapon &weapon);
	~HumanA();
	void attack(void);
};

#endif
