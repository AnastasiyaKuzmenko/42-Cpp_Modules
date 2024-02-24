/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:34:54 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/24 12:26:05 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << "\033[35m" << "print char array" << "\033[0m" << std::endl;
	char array_str[] = {'a', 'A', 'b', 'B'};
	iter<char>(array_str, (unsigned int)4, printValue);

	std::cout << std::endl;
	std::cout << "\033[35m" << "print int array" << "\033[0m" << std::endl;
	int array_int[] = {1, 2, 3, 4, 5, 6, 7};
	iter<int>(array_int, (unsigned int)7, printValue);

	std::cout << std::endl;
	std::cout << "\033[35m" << "print float array" << "\033[0m" << std::endl;
	float array_float[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f};
	iter<float>(array_float, (unsigned int)7, printValue);

	std::cout << std::endl;
	std::cout << "\033[35m" << "print string array" << "\033[0m" << std::endl;
	std::string array_string[] = {"aaa", "bbb", "ccc"};
	iter<std::string>(array_string, (unsigned int)3, printValue);

	return 0;
}
