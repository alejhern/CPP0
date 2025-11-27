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

static Contact	create_contact(void)
{
	string	first_name;
	string	last_name;
	string	nickname;
	string	phone_number;

	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	return (Contact(first_name, last_name, nickname, phone_number));
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
	string		command;

	phonebook = Phonebook();
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add_contact(create_contact());
		else if (command == "SEARCH")
			search_contact(phonebook);
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return (0);
}
