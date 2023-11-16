/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:40:21 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/26 14:27:21 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <iomanip> 
# include <string>
# include "Contact.hpp"
# include "PhoneBook.hpp"

Contact addNewContact();
void 	showAllContacts(PhoneBook phonebook);
void	searchContact(PhoneBook phonebook);
int		isNotDigit(std::string number);

#endif
