/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:51:59 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/02/24 12:41:05 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << "Empty array" << std::endl;
	Array<int> emptyArray;
	try
	{
		std::cout << "Size: " << emptyArray.size() << std::endl;
		std::cout << "Trying to print from empty array: " << std::endl << emptyArray[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Int array" << std::endl;
	Array<int> intArray(7);
	for (int i = 0; i < 7; i++)
		intArray[i] = i;
	std::cout << "Size: " << intArray.size() << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << intArray[i] << "  ";
	std::cout << std::endl << std::endl;

	std::cout << "Double array" << std::endl;
	Array<double> doubleArray(10);
	for (int i = 0; i < 7; i++)
		doubleArray[i] = i + 0.3;
	std::cout << "Size: " << doubleArray.size() << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << doubleArray[i] << "  ";
	std::cout << std::endl << std::endl;

	std::cout << "Trying to print negative value" << std::endl;
	try
	{
		std::cout << intArray[-3] << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Trying to print too high value" << std::endl;
	try 
	{
		std::cout << intArray[12] << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Testing copy constructor" << std::endl;
	Array<int> intArray2(intArray);
	std::cout << "First array" << std::endl;
	std::cout << "Size: " << intArray.size() << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << intArray[i] << "  ";
	std::cout << std::endl << "Second array" << std::endl;
	std::cout << "Size: " << intArray2.size() << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << intArray2[i] << "  ";
	std::cout << std::endl << std::endl;


	std::cout << std::endl << "Tests given in subject: " << std::endl;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//

	return 0;
}
