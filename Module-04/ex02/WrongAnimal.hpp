/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:42:44 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/13 13:06:48 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &source);
	WrongAnimal &operator=(const WrongAnimal &source);
	virtual ~WrongAnimal();

	std::string getType(void) const;
	void makeSound() const;
};

#endif
