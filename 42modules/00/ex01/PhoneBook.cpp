/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:04:32 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/25 15:13:40 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"

static std::string formatField(const std::string &str)
{
	if (str.size() > 10)
	{
		return str.substr(0, 9) + ".";
	}
	std::string out = str;
	while (out.size() < 10)
		out = " " + out;
	return out;
}

PhoneBook::PhoneBook() : _count(0) {} //obj of phonebook ,no dynam alloc

void PhoneBook::append(const Contact &contact)
{
	if (_count < _max_size) //if enough space
	{
		_contacts[_count] = contact;
		_count++;
	}
	else // if full shift to the left
	{
		int i = 0;
		while (i < _max_size - 1)
		{
			_contacts[i] = _contacts[i + 1];
			i++;
		}
		_contacts[_max_size - 1] = contact;
	}
}

static bool readNonEmptyLine(const std::string &prompt, std::string &out)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, out))
			return false;
		if (!out.empty())
			return true;
		std::cout << "Field cannot be empty. Try again." << std::endl;
	}
}

void PhoneBook::add()
{
	Contact c;
	std::string input;

	if (!readNonEmptyLine("First name: ", input))
		return;
	c.setFirstName(input);

	if (!readNonEmptyLine("Last name: ", input))
		return;
	c.setLastName(input);

	if (!readNonEmptyLine("Nickname: ", input))
		return;
	c.setNickname(input);

	if (!readNonEmptyLine("Phone number: ", input))
		return;
	c.setPhoneNumber(input);

	if (!readNonEmptyLine("Darkest Secret: ", input))
		return;
	c.setDarkestSecret(input);

	append(c);
	std::cout << "Contact added." << std::endl;
}

void PhoneBook::search()
{
	if (_count == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << formatField("index")
			  << "|" << formatField("first name")
			  << "|" << formatField("last name")
			  << "|" << formatField("nickname") << "|" << std::endl;
	std::cout << "---------------------------------------------" <<std::endl;

	for (int i = 0; i < _count; i++)
	{
		std::cout << "|" << formatField(std::string(1, '0' + i))
		          << "|" << formatField(_contacts[i].getFirstName())
		          << "|" << formatField(_contacts[i].getLastName())
		          << "|" << formatField(_contacts[i].getNickname())
		          << "|" << std::endl;
 	}
 	std::cout << "---------------------------------------------" << std::endl;

 	std::string input;
 	std::cout << "Enter index to view details: ";
 	if (!std::getline(std::cin, input))
 		return;
 	if (input.size() != 1 || input[0] < '0' || input[0] > '7')
 	{
 		std::cout << "Invalid index." << std::endl;
 		return;
 	}
 	int idx = input[0] - '0';
 	if (idx < 0 || idx >= _count)
 	{
 		std::cout << "No contact at that index." << std::endl;
 		return;
 	}
 	const Contact &c = _contacts[idx];
 	std::cout << "First name: " << c.getFirstName() << std::endl;
 	std::cout << "Last name: " << c.getLastName() << std::endl;
 	std::cout << "Nickname: " << c.getNickname() << std::endl;
 	std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
 	std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

void PhoneBook::run()
{
	std::string cmd; //str buffer

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			break ;
		if (cmd == "ADD")
			add();
		else if (cmd == "SEARCH")
			search();
		else if (cmd == "EXIT")
			break;
		else if (cmd.size() == 0)
			continue;
		else
			continue;
	}

}