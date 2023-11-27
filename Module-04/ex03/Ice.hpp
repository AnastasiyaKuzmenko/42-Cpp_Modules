/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:50:34 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/11/16 13:58:12 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria
{

public:
	Ice();
	Ice(Ice const & source);
	Ice& operator=(Ice const & source);
	~Ice();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
