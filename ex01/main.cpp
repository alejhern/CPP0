/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:53:18 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/27 13:53:24 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

static string	get_field_input(const string &prompt)
{
	string	input;

	std::cout << prompt;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Input cannot be empty. " << prompt;
		if (std::cin.eof())
			exit(0);
		std::getline(std::cin, input);
	}
	return (input);
}

static Contact	create_contact(void)
{
	string	first_name;
	string	last_name;
	string	nickname;
	string	phone_number;
	string	darkest_secret;

	first_name = get_field_input("Enter first name: ");
	last_name = get_field_input("Enter last name: ");
	nickname = get_field_input("Enter nickname: ");
	phone_number = get_field_input("Enter phone number: ");
	darkest_secret = get_field_input("Enter darkest secret: ");
	return (Contact(first_name, last_name, nickname, phone_number, darkest_secret));
}

static void update_last_contact(Phonebook &phonebook)
{
	int		last_index;
	Contact *contact;

	last_index = phonebook.get_contact_count() - 1;
	if (last_index < 0)
		return;
	contact = phonebook.get_contact(last_index);
	std::cout << "---- UPDATING LAST CONTACT (Index " << last_index << "):" << std::endl;
	phonebook.display_contact(last_index);
	std::cout << "----Enter new details for the contact:----" << std::endl;
	contact->set_first_name(get_field_input("Enter new first name: "));
	contact->set_last_name(get_field_input("Enter new last name: "));
	contact->set_nickname(get_field_input("Enter new nickname: "));
	contact->set_phone_number(get_field_input("Enter new phone number: "));
	contact->set_darkest_secret(get_field_input("Enter new darkest secret: "));
	std::cout << "Contact updated successfully." << std::endl;
}

static void	search_contact(const Phonebook &phonebook)
{
	string	index_str;
	int		index;

	if (phonebook.get_contact_count() == 0)
	{
		std::cout << "Phonebook is empty. Please add a contact first." << std::endl;
		return ;
	}
	phonebook.display_all_contacts();
	std::cout << "Enter index of contact to display: ";
	std::getline(std::cin, index_str);
	try
	{
		index = std::stoi(index_str);
		phonebook.display_contact(index);
	}
	catch (const std::exception &e)
	{
		std::cout << "Invalid index. Please try again." << std::endl;
	}
}

int	main(void)
{
	Phonebook	phonebook;
	Contact		contact;
	string		command;

	phonebook = Phonebook();
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break ;
		if (command == "ADD")
		{
			if (phonebook.get_contact_count() >= MAX_CONTACTS)
				update_last_contact(phonebook);
			else
				phonebook.add_contact(create_contact());
		}
		else if (command == "SEARCH")
			search_contact(phonebook);
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return (0);
}
