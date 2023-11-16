/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:12:07 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/24 16:28:56 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
# define MAX_CONTACT 8

class PhoneBook
{
private:
	Contact contacts[MAX_CONTACT];
	int	current_index;
	int	entry_count;
public:
	void fillPhonebook(Contact contact);
	Contact getContact(int index) const;
	int getEntryCount() const;
	PhoneBook();
	~PhoneBook();
};

#endif
