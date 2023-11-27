/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:58:19 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/16 13:59:14 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria
{

public:
	Cure();
	Cure(Cure const & source);
	Cure& operator=(Cure const & source);
	~Cure();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
