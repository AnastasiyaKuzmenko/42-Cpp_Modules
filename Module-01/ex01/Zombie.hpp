/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:49:19 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/31 14:21:33 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HORDE_HPP
# define HORDE_HPP
# include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();
	void announce(void);
	void setName(std::string str);
	std::string getName(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
