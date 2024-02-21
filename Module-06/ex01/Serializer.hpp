/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:52:07 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/09 11:21:20 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIAIZER_HPP
# define SERIAIZER_HPP

# include <cstdint>
# include "data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &source);
	Serializer &operator=(const Serializer &source);
	~Serializer();

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
