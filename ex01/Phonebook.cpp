/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:33:37 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/27 15:57:04 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_contact_count = 0;
};

void Phonebook::add_contact(const Contact &contact)
{
	this->_contacts[this->_contact_count % MAX_CONTACTS] = contact;
	this->_contact_count++;
};
Contact *Phonebook::get_contact(int index)
{
	if (index < 0 || index >= std::min(this->_contact_count, MAX_CONTACTS))
		throw std::out_of_range("Index out of range");
	return (&this->_contacts[index]);
};

int Phonebook::get_contact_count(void) const
{
	return (std::min(this->_contact_count, MAX_CONTACTS));
};

void Phonebook::display_contact(int index) const
{
	if (index < 0 || index >= std::min(this->_contact_count, MAX_CONTACTS))
	{
		std::cout << "Index out of range" << std::endl;
		return ;
	}
	Contact contact = this->_contacts[index];
	std::cout << "First Name: " << contact.get_first_name() << std::endl;
	std::cout << "Last Name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_darkest_secret() << std::endl;
};

void Phonebook::display_all_contacts(void) const
{
	int contacts_len;
	int i;

	std::cout << std::setw(5) << "Index"
				<< " | " << std::setw(10) << "First Name"
				<< " | " << std::setw(10) << "Last Name"
				<< " | " << std::setw(10) << "Nickname"
				<< " | " << std::setw(15) << "Phone Number" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	contacts_len = this->get_contact_count();
	i = -1;
	while (++i < contacts_len)
	{
		Contact contact = this->_contacts[i];
		std::cout << std::setw(5) << i << " | ";
		std::cout << std::setw(10) << (contact.get_first_name().length() > 10 ? contact.get_first_name().substr(0,
				9) + "." : contact.get_first_name()) << " | ";
		std::cout << std::setw(10) << (contact.get_last_name().length() > 10 ? contact.get_last_name().substr(0,
				9) + "." : contact.get_last_name()) << " | ";
		std::cout << std::setw(10) << (contact.get_nickname().length() > 10 ? contact.get_nickname().substr(0,
				9) + "." : contact.get_nickname()) << " | ";
		std::cout << std::setw(15) << (contact.get_phone_number().length() > 15 ? contact.get_phone_number().substr(0,
				14) + "." : contact.get_phone_number()) << std::endl;
	}
};
