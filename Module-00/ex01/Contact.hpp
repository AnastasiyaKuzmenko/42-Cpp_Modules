/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:31:50 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/10/24 17:33:02 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	~Contact();
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	void setFirstName(std::string input_first_name);
	void setLastName(std::string input_last_name);
	void setNickname(std::string input_nickname);
	void setPhoneNumber(std::string input_phone_number);
	void setDarkestSecret(std::string input_darkest_secret);
};

#endif
