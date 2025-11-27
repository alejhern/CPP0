/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:33:04 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/27 13:33:07 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define MAX_CONTACTS 8

# include <cctype>
# include <iomanip>
# include <iostream>
# include <stdexcept>
# include <string>
typedef std::string string;

class Contact
{
  private:
	string _first_name;
	string _last_name;
	string _nickname;
	string _phone_number;

  public:
	Contact(void);
	Contact(string fn, string ln, string nn, string pn);
	string get_first_name(void) const;
	string get_last_name(void) const;
	string get_nickname(void) const;
	string get_phone_number(void) const;
	void set_first_name(string fn);
	void set_last_name(string ln);
	void set_nickname(string nn);
	void set_phone_number(string pn);
};

class Phonebook
{
  private:
	Contact _contacts[MAX_CONTACTS];
	int _contact_count;

  public:
	Phonebook(void);
	void add_contact(const Contact &contact);
	Contact get_contact(int index);
	int get_contact_count(void) const;
	void display_contact(int index) const;
	void display_all_contacts(void) const;
};

#endif
