/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:28:44 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/24 16:19:42 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	char	c;
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				c = std::toupper(argv[i][j]);
				std::cout << c;
			}
			if (i != argc - 1)
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
