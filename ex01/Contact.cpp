/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:17:50 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/27 15:56:44 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contact::Contact(){};

Contact::Contact(string fn, string ln, string nn, string pn, string ds)
{
	this->_first_name = fn;
	this->_last_name = ln;
	this->_nickname = nn;
	this->_phone_number = pn;
	this->_darkest_secret = ds;
}

string Contact::get_first_name(void) const
{
	return (this->_first_name);
};

string Contact::get_last_name(void) const
{
	return (this->_last_name);
};

string Contact::get_nickname(void) const
{
	return (this->_nickname);
};

string Contact::get_phone_number(void) const
{
	return (this->_phone_number);
};

string Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
};

void Contact::set_first_name(string fn)
{
	this->_first_name = fn;
};

void Contact::set_last_name(string ln)
{
	this->_last_name = ln;
};

void Contact::set_nickname(string nn)
{
	this->_nickname = nn;
};

void Contact::set_phone_number(string pn)
{
	this->_phone_number = pn;
};

void Contact::set_darkest_secret(string ds)
{
	this->_darkest_secret = ds;
};