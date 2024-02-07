/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:16:20 by akuzmenk          #+#    #+#             */
/*   Updated: 2024/01/30 17:16:23 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
private:
	static AForm *makeShrubberyForm(std::string const target);
	static AForm *makePresidentialForm(std::string const target);
	static AForm *makeRobotomyForm(std::string const target);

public:
	Intern();
	Intern(const Intern &source);
	Intern &operator=(const Intern &source);
	~Intern();

	AForm *makeForm(std::string form_name, std::string target);
};

#endif
