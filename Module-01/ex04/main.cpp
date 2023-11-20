/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:33:23 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/31 14:54:47 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replace_line(std::string line, std::string original_str, std::string replacement_str)
{
	size_t pos = 0;
	size_t len_original = original_str.length();
	size_t len_replace = replacement_str.length();

	while (1)
	{
		pos = line.find(original_str, pos);
		if (pos == std::string::npos)
		{
			return line;
		}
		else
		{
			line.erase(pos, len_original);
			line.insert(pos, replacement_str);
			pos += len_replace;
		}
	}
	return line;
}

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr <<"\033[31m" << "Wrong number of arguments" << "\033[0m" << std::endl;
		return 1;
	}
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		std::cerr <<"\033[31m" << "One of the strings is empty" << "\033[0m" << std::endl;
		return 1;
	}
	std::string input_filename = argv[1];
	std::string original_str = argv[2];
	std::string replacement_str = argv[3];
	std::string output_filename = input_filename + ".replace";
	std::string line;

	std::ifstream input_file(input_filename);
	if (!input_file.is_open())
	{
		std::cerr <<"\033[31m" << "Fail to open source file"<< "\033[0m" << std::endl;
		return 1;
	}
	
	std::ofstream output_file(output_filename);
	if (!output_file.is_open())
	{
		std::cerr <<"\033[31m" << "Fail to open output file"<< "\033[0m" << std::endl;
		return 1;
	}

	while (std::getline(input_file, line))
	{
		line = replace_line(line, original_str, replacement_str);
		output_file << line;
		if (input_file.peek() != EOF)
			output_file << std::endl;
	}
	output_file.close();
	input_file.close();
	return 0;
}
