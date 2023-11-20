/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:26:11 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/31 15:09:47 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl();
	~Harl();
	void complain(std::string level);
};

#endif
